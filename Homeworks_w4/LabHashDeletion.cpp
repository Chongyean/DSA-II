#include<iostream>
using namespace std;
#define ArraySize 200

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

        newIndex = (newIndex + 1) % ArraySize;

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
            return true; // Item found at new index
        }

        newIndex = (newIndex + 1) % ArraySize; // Linear probing
        if (newIndex == index) {
            break; // We have looped through the table
        }
    }
    return false; // Item not found
    
}

void InsertIntoHashTable(string word) {
    int index = HashFunction(word);
    int newIndex = Collision(index);
    
    //Check if the index is tombstone
    if (HashTable[index] == "Tombstone") {
        HashTable[index] = word; // If the original index is a tombstone, replace it with the new word
        cout << "Inserted word: " << word << " at index: " << index << endl;
        return;
    }
    // If there is a collision, find a new index
    if (newIndex != -1) {

        HashTable[newIndex] = word; // Insert the word at the new index
        cout << "Inserted word: " << word << " at index: " << newIndex << endl;
    } 
    else {

        HashTable[index] = word; // Insert the word at the original index if no collision or tombstone
    }
}

void DeleteFromHashTable(string word) {
    int index = HashFunction(word);
    int newIndex = index;

    //Find the word in the hash table based on Tombstone deletion
    while (HashTable[newIndex] != "") {
        if (HashTable[newIndex] == word) {
            HashTable[newIndex] = "Tombstone"; // Mark the slot as deleted
            cout << "Deleted word: " << word << " from index: " << newIndex << endl;
            return;
        }
        newIndex = (newIndex + 1) % ArraySize; // Linear probing
        if (newIndex == index) {
            break; // We have looped through the table
        }
    }
}  

int main() {
    string word;
    int choice;

    while (true) {
        cout << "===============================================\n";
        cout << "1. Insert into Hash Table\n";
        cout << "2. Search in Hash Table\n";
        cout << "3. Delete from Hash Table\n";
        cout << "4. Display HashTable\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                InsertIntoHashTable(word);
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                if (SearchInHashTable(word)) {
                    cout << "Word found in hash table.\n";
                } else {
                    cout << "Word not found in hash table.\n";
                }
                break;
            case 3:
                cout << "Enter word to delete: ";
                cin >> word;
                DeleteFromHashTable(word);
                break;
            case 4:
                cout << "Hash Table contents:\n";
                for (int i = 0; i < ArraySize; i++) {
                    if (HashTable[i] != "") {
                        cout << "Index " << i << ": " << HashTable[i] << endl;
                    }
                }
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}

