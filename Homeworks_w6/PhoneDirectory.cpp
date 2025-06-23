#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// Task 1 : Decide which map type to use and declare it
unordered_map<string, int> phoneDirectory;

// Task 2: Implement these functions
void addContact(string name, int phoneNumber) {

// Add new contact or update existing one
    cout << "Enter contact name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    // Add or update contact
    phoneDirectory[name] = phoneNumber;
    cout << "Contact added/updated successfully." << endl;
}

void deleteContact(string name) {

// Delete a contact if exists
    cout << "Enter contact name to delete: ";
    cin >> name;

    auto it = phoneDirectory.find(name);
    if (it != phoneDirectory.end()) {
        phoneDirectory.erase(it);
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }

}

void searchContact(string name) {

// Search and print contact details
    cout << "Enter contact name to search: ";
    cin >> name;

    auto it = phoneDirectory.find(name);
    if (it != phoneDirectory.end()) {
        cout << "Contact found : " << it->first << " - " << it->second << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void updateContact(string name, int phoneNumber) {
    // Update an existing contact
    cout << "Enter contact name to update: ";
    cin >> name;
    cout << "Enter new phone number: ";
    cin >> phoneNumber;

    auto it = phoneDirectory.find(name);
    if (it != phoneDirectory.end()) {
        it->second = phoneNumber;
        cout << "Contact updated successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void displayAllContacts() {

// Display all contacts
    cout << "====== Phone Directory ======" << endl;
    for (const auto& contact : phoneDirectory) {
        cout << contact.first << " : " << contact.second << endl;
    }
    cout << "=============================" << endl;
}

int main(){

    int choice;
    string name;
    int phoneNumber;

    do {
        cout << "====== Phone Directory Menu ======" << endl;

        cout << "1. Add Contact" << endl;
            // - "Dara": "012345678"
            // - "Bopha": "023456789"
            // - "Sokha": "034567890"
        cout << "2. Search Contact" << endl; //"Dara"
        cout << "3. Update Contact" << endl; //"Bopha" ,  "098765432"
        cout << "4. Delete Contact" << endl; //"Sokha"
        cout << "5. Display All Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(name, phoneNumber);
                system("cls");
                cout << "Contact added successfully." << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get(); // Wait for user input before clearing the screen
                system("cls");
                break;
            case 2:
                searchContact(name);
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 3:
                updateContact(name, phoneNumber);
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 4:
                deleteContact(name);
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 5:
                displayAllContacts();
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}