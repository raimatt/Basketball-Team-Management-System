#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addPerformance() {
    ofstream file("performances.txt", ios::app);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    string team, outcome;
    int points;
    cout << "Enter team name: ";
    cin.ignore();
    getline(cin, team);
    cout << "Enter outcome (W/L): ";
    getline(cin, outcome);
    cout << "Enter total points: ";
    cin >> points;
    file << team << "," << outcome << "," << points << endl;
    file.close();
    cout << "Performance added successfully." << endl;
}

void displayPerformances() {
    ifstream file("performances.txt");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    string line;
    cout << "Performance Records:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    cout << "Microservice B: Performance Analysis" << endl;
    cout << "1. Add Performance" << endl;
    cout << "2. Display Performances" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        addPerformance();
    } else if (choice == 2) {
        displayPerformances();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
