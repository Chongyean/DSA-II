#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 200;

class HashTable {
private:
    string table[TABLE_SIZE];

    int hashFunction(const string& word) {
        if (word.length() != 2) return -1; // 2-char words
        return (word[0] * 31 + word[1]) % TABLE_SIZE;
    }

public:
    void insert(const string& word) {
        int index = hashFunction(word);
        if (index == -1) {
            cout << "Invalid word: " << word << endl;
            return;
        }

        int startIndex = index;
        while (!table[index].empty()) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }
        table[index] = word;
    }

    bool search(const string& word) {
        int index = hashFunction(word); // Hash the word to find the index
        if (index == -1) 
            return false;

        int startIndex = index;
        while (!table[index].empty()) { // Collision with linear probing concept
            if (table[index] == word)
                return true;
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) 
                break;
        }
        return false;
    }   

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty())
                cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;

    // Example insertions
    ht.insert("ck");
    ht.insert("ak");
    ht.insert("zk");

    // Example search
    cout << "Searching for 'ck': " << (ht.search("ck") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'zz': " << (ht.search("zz") ? "Found" : "Not Found") << endl;

    // Optional display
    ht.display();

    return 0;
}
