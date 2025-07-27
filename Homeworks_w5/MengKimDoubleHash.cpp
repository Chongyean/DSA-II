#include<iostream>
using namespace std;
#define ArraySize 200

string HashTable[ArraySize];

int HashFunction(string word, int& HugeNumber) {
    HugeNumber = 0;
    int base = 27; 
    int power = 1;

    for (int i = 0; i < word.size(); i++) {
        HugeNumber += (word[i] - 'a' + 1) * power; 
        power *= base; // Increase the power of the base for the next character
    }

    return HugeNumber % ArraySize;
}

int DoubleHashing(string word) {
    int HugeNumber = 0;
    int index = HashFunction(word, HugeNumber);

    //Calculate step size using formula: stepSize = constant - (key % constant)
    int stepSize = 7 - (HugeNumber % 7); 
    int newIndex = index; 

    while (HashTable[newIndex] != "") {

        newIndex = (newIndex + stepSize) % ArraySize; //Double hashing

    }
    return newIndex; //Return the new index where the item can be inserted
}

void InsertIntoHashtable(string word) {
    int HugeNumber = 0;
    int index = HashFunction(word, HugeNumber);
    
    if (HashTable[index] == "") {

        HashTable[index] = word; // Insert the word into the hash table
        cout << "Inserted word: " << word << " at index: " << index << endl;
    }
    else {
        
        int newIndex = DoubleHashing(word);
        HashTable[newIndex] = word; // Insert the word into the hash table at the new index
        cout << "Inserted word: " << word << " at index: " << newIndex << endl;
    }
    return;
}

void SearchInHashTable(string word) {
    int HugeNumber = 0; 
    int index = HashFunction(word, HugeNumber);
    int stepSize = 7 - (HugeNumber % 7);

    // Handle collision using double hashing
    while (HashTable[index] != "") {
        if (HashTable[index] == word) {
            cout << "Word found: " << word << " at index: " << index << endl;
            return;
        }
        index = (index + stepSize) % ArraySize; // Double hashing

        if (index == HugeNumber % ArraySize) {
            break; // We have looped through the table
        }
    }
    cout << "Word not found: " << word << endl;
}

int main() {
    string word;
    int choice;

    while (true) {
        cout << "===============================================\n";
        cout << "1. Insert into Hash Table\n";
        cout << "2. Search in Hash Table\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                InsertIntoHashtable(word);
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                SearchInHashTable(word);
                break;
            case 3:
                cout << "Hash Table Contents:\n";
                for (int i = 0; i < ArraySize; i++) {
                    if (HashTable[i] != "") {
                        cout << "Index " << i << ": " << HashTable[i] << endl;
                    }
                }
                break;
            case 4:
                return 0; // Exit the program
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;   
}
