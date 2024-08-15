#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addItem() {
    ofstream file("inventory.txt", ios::app);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    string item, quantity;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, item);
    cout << "Enter quantity: ";
    getline(cin, quantity);
    file << item << "," << quantity << endl;
    file.close();
    cout << "Item added successfully." << endl;
}

void displayInventory() {
    ifstream file("inventory.txt");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    string line;
    cout << "Inventory:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    cout << "Microservice C: Inventory Management" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Display Inventory" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        addItem();
    } else if (choice == 2) {
        displayInventory();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
