#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Activity {
    string date;
    string description;
};

struct TeamStats {
    string previous_game_outcome;
    int wins;
    int losses;
    string top_performer;
};

struct BoxScore {
    string team_played;
    string wl;
    int total_points;
};

struct Event {
    string date;
    string description;
};

void displayDashboard(const Activity* activities, int activityCount, const TeamStats& stats, const Event* events, int eventCount) {
    cout << "===== TEAM DASHBOARD =====" << endl << endl;

    // display team activities
    cout << "Team Activities:" << endl;
    for (int i = 0; i < activityCount; ++i) {
        cout << "- " << activities[i].date << ": " << activities[i].description << endl;
    }
    cout << endl;

    // display team stats
    cout << "Team Stats:" << endl;
    cout << "Previous Game Outcome: " << stats.previous_game_outcome << endl;
    cout << "Team Record: " << "Wins: " << stats.wins << " " << "Losses: " << stats.losses << endl;
    cout << "Top Performer: " << stats.top_performer << endl << endl;

    // display upcoming events
    cout << "Upcoming Events:" << endl;
    for (int i = 0; i < eventCount; ++i) {
        cout << "- " << events[i].date << ": " << events[i].description << "\n";
    }
    cout << endl;

    cout << "==========================" << endl;
}

void deleteActivity(Activity*& activities, int& activityCount) {
    cout << "Enter the index of the activity to delete (0 to " << (activityCount - 1) << "): ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 0 || index >= activityCount) {
        cout << "Invalid index!" << endl;
        return;
    }

    string prevent_error;
    cout << "Are you sure you want to delete this activity? (yes, no) ";
    cin >> prevent_error;
    if (prevent_error == "no") {
        return;
    }

    Activity* newActivities = new Activity[activityCount - 1];
    for (int i = 0, j = 0; i < activityCount; ++i) {
        if (i != index) {
            newActivities[j++] = activities[i];
        }
    }

    delete[] activities;
    activities = newActivities;
    --activityCount;

    cout << "Activity Successfully Deleted!" << endl << endl;
}

void deleteEvent(Event*& events, int& eventCount) {
    cout << "Enter the index of the event to delete (0 to " << (eventCount - 1) << "): ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 0 || index >= eventCount) {
        cout << "Invalid index!" << endl;
        return;
    }

    string prevent_error;
    cout << "Are you sure you want to delete this activity? (yes, no) ";
    cin >> prevent_error;
    if (prevent_error == "no") {
        return;
    }

    Event* newEvents = new Event[eventCount - 1];
    for (int i = 0, j = 0; i < eventCount; ++i) {
        if (i != index) {
            newEvents[j++] = events[i];
        }
    }

    delete[] events;
    events = newEvents;
    --eventCount;

    cout << "Event Successfully Deleted!" << endl << endl;
}

void detailedTeamStats(const BoxScore& boxscore) {
    cout << "======= BOX SCORES =======" << endl;
    cout << "GAME 1: " << endl;
    cout << "Team Played: " << boxscore.team_played << endl;
    cout << "W/L: " << boxscore.wl << endl;
    cout << "Total Points: " << boxscore.total_points << endl;
    cout << "==========================" << endl;
}

void handlePlayerProfile() {
    cout << "Handling Player Profiles:" << endl;
    cout << "1. Add Player" << endl;
    cout << "2. Display Players" << endl;
    int choice;
    cin >> choice;
    ofstream file;
    file.open("microserviceA.txt");
    if (choice == 1) {
        file << "Add Player\n";
    } else if (choice == 2) {
        file << "Display Players\n";
    } else {
        cout << "Invalid choice!" << endl;
    }
    file.close();
    system("./microserviceA");
}

void handlePerformanceAnalysis() {
    cout << "Handling Performance Analysis:" << endl;
    cout << "1. Add Performance" << endl;
    cout << "2. Display Performances" << endl;
    int choice;
    cin >> choice;
    ofstream file;
    file.open("microserviceB.txt");
    if (choice == 1) {
        file << "Add Performance\n";
    } else if (choice == 2) {
        file << "Display Performances\n";
    } else {
        cout << "Invalid choice!" << endl;
    }
    file.close();
    system("./microserviceB");
}

void handleInventoryManagement() {
    cout << "Handling Inventory Management:" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Display Inventory" << endl;
    int choice;
    cin >> choice;
    ofstream file;
    file.open("microserviceC.txt");
    if (choice == 1) {
        file << "Add Item\n";
    } else if (choice == 2) {
        file << "Display Inventory\n";
    } else {
        cout << "Invalid choice!" << endl;
    }
    file.close();
    system("./microserviceC");
}

int main() {
    cout << "==========================" << endl;
    cout << "=== Welcome to HoopHub ===" << endl;
    cout << "==========================" << endl;
    cout << endl;

    string username, password;
    cout << "CREATE ACCOUNT:" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    cout << "Account Successfully Created!" << endl << endl;

    cout << "Hello " << username << "," << endl << endl;

    int activityCount = 0;
    int eventCount = 0;
    Activity* activities = nullptr;
    Event* events = new Event[eventCount];

    TeamStats stats = {
        "Won against Tigers",
        10,
        2,
        "John Doe"
    };

    BoxScore boxscore = {
        "Tigers",
        "W",
        87
    };

    displayDashboard(activities, activityCount, stats, events, eventCount);
    cout << endl << endl;

    int choice;
    do {
        cout << "Control Center:" << endl;
        cout << "1. View Dashboard" << endl;
        cout << "2. Additional Team Details (Box Score)" << endl;
        cout << "3. Manage Team Activities (Add, Delete)" << endl;
        cout << "4. Manage Events (Add, Delete)" << endl;
        cout << "5. Manage Player Profiles (via Microservice A)" << endl;
        cout << "6. Manage Performance Analysis (via Microservice B)" << endl;
        cout << "7. Manage Inventory (via Microservice C)" << endl;
        cout << "8. Quit" << endl;
        cin >> choice;

        if (choice == 1) {
            displayDashboard(activities, activityCount, stats, events, eventCount);
            cout << endl << endl;
        } else if (choice == 2) {
            detailedTeamStats(boxscore);
        } else if (choice == 3) {
            int choice;
            cout << "How would you like to manage your team activities?" << endl;
            cout << "1. Add Activity (number of activities, date, description)" << endl;
            cout << "2. Delete Activity (index of activity)" << endl;
            cout << "3. Back" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Enter the number of new activities to add: ";
                int newActivityCount;
                cin >> newActivityCount;
                cin.ignore();
                if (newActivityCount == 0) {
                    continue;
                }

                Activity* newActivities = new Activity[activityCount + newActivityCount];
            
                for (int i = 0; i < activityCount; ++i) {
                    newActivities[i] = activities[i];
                }
            
                for (int i = 0; i < newActivityCount; ++i) {
                    cout << "Enter date for activity " << (activityCount + i + 1) << ": ";
                    getline(cin, newActivities[activityCount + i].date);
                    cout << "Enter description for activity " << (activityCount + i + 1) << ": ";
                    getline(cin, newActivities[activityCount + i].description);
                }

                activityCount += newActivityCount;
                delete[] activities;
                activities = newActivities;

                cout << "Activities Successfully Added!" << endl;
            } else if (choice == 2) {
                deleteActivity(activities, activityCount);
            } else if (choice == 3) {
                continue;
            }
        } else if (choice == 4) {
            int choice;
            cout << "How would you like to manage your events?" << endl;
            cout << "1. Add Event (number of events, date, description)" << endl;
            cout << "2. Delete Event (index of event)" << endl;
            cout << "3. Back" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Enter the number of new events to add: ";
                int newEventCount;
                cin >> newEventCount;
                cin.ignore();
                if (newEventCount == 0) {
                    continue;
                }

                Event* newEvents = new Event[eventCount + newEventCount];
            
                for (int i = 0; i < eventCount; ++i) {
                    newEvents[i] = events[i];
                }
            
                for (int i = 0; i < newEventCount; ++i) {
                    cout << "Enter date for event " << (eventCount + i + 1) << ": ";
                    getline(cin, newEvents[eventCount + i].date);
                    cout << "Enter description for event " << (eventCount + i + 1) << ": ";
                    getline(cin, newEvents[eventCount + i].description);
                }

                eventCount += newEventCount;
                delete[] events;
                events = newEvents;

                cout << "Events Successfully Added!" << endl;
            } else if (choice == 2) {
                deleteEvent(events, eventCount);
            } else if (choice == 3) {
                continue;
            }
        } else if (choice == 5) {
            handlePlayerProfile();
        } else if (choice == 6) {
            handlePerformanceAnalysis();
        } else if (choice == 7) {
            handleInventoryManagement();
        }
    } while (choice != 8);

    if (choice == 8) {
        cout << "Exiting HoopHub..." << endl;
        return 0;
    }

    // clean up dynamically allocated memory
    delete[] activities;
    delete[] events;

    return 0;
}
