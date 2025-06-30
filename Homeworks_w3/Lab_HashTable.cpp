#include<iostream>
#define ArraySize 100
using namespace std;

string HashTable[ArraySize];

int HashFunction(string word) {
    int HugeNumber = 0;
    int base = 27;
    int power = 1;

    for (int i = 0; i < word.size(); i++) {
        HugeNumber += (word[i] - 'a' + 1) * power;
        power *= base;
    }

    return HugeNumber % ArraySize;
}

int Collision(int IndexOfHashTable) {

    int newIndex = IndexOfHashTable;
    while (HashTable[newIndex] != "") {

        newIndex = (newIndex + 1) % ArraySize; // Linear probing

        if (newIndex == IndexOfHashTable) {

            return -1;
        }
    }

    return newIndex;
}

bool SearchInHashTable(string word) {
    int index = HashFunction(word);
    int newIndex = index;
    
    // Handle collision using linear probing
    while (HashTable[newIndex] != "") {

        if (HashTable[newIndex] == word) {
            return true;
        }

        newIndex = (newIndex + 1) % ArraySize; // Linear probing
        if (newIndex == index) {
            break;
        }
    }
    return false;
    
}

void InsertIntoHashTable(string word) {
    int index = HashFunction(word);
    int newIndex = Collision(index);
    
    // If there is a collision, find a new index
    if (HashTable[index] == "") {

        HashTable[index] = word;
        cout << "Inserted word: " << word << " at index: " << newIndex << endl;
    } 
    else if (newIndex != -1) {

        HashTable[newIndex] = word;
        cout << "Inserted word: " << word << " at index: " << newIndex << endl;
    }
    else {
        cout << "Hash table is full, cannot insert word: " << word << endl;
    }
}

int main() {
    string word;
    int choice;

    while (true) {
        cout << "===============================================\n";
        cout << "Choose an option:\n";
        cout << "1. Insert a word into the hash table\n";
        cout << "2. Search for a word in the hash table\n";
        cout << "3. Display hash table contents\n";
        cout << "4. Exit\n";
        cout << "===============================================\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a word to insert into the hash table: ";
                cin >> word;
                InsertIntoHashTable(word);
                break;
            
            case 2:
                cout << "Enter a word to search in the hash table: ";
                cin >> word;
                if (SearchInHashTable(word)) {
                    cout << "Word '" << word << "' found in the hash table." << endl;
                } else {
                    cout << "Word '" << word << "' not found in the hash table." << endl;
                }
                break;

            case 3:
                cout << "Hash table contents:" << endl;
                for (int i = 0; i < ArraySize; i++) {
                    if (HashTable[i] != "") {
                        cout << "Index " << i << ": " << HashTable[i] << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
