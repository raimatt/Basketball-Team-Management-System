#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addPlayer() {
    ofstream file("player_profiles.txt", ios::app);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    string name, position;
    cout << "Enter player name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter player position: ";
    getline(cin, position);
    file << name << "," << position << endl;
    file.close();
    cout << "Player added successfully." << endl;
}

void displayPlayers() {
    ifstream file("player_profiles.txt");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    string line;
    cout << "Player Profiles:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    cout << "Microservice A: Player Profile Management" << endl;
    cout << "1. Add Player" << endl;
    cout << "2. Display Players" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        addPlayer();
    } else if (choice == 2) {
        displayPlayers();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
