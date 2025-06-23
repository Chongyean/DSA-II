#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class EntryState { EMPTY, OCCUPIED, TOMBSTONE };

struct Entry {
    int key;
    string value;
    EntryState state;

    Entry() : key(0), value(""), state(EntryState::EMPTY) {}
};

class HashTable {
private:
    static const int SIZE = 10;
    vector<Entry> table;

    int hashFunction(int key) const {
        return key % SIZE;
    }

public:
    HashTable() : table(SIZE) {}

    void insert(int key, const string& value) {
        int index = hashFunction(key);
        int originalIndex = index;
        do {
            if (table[index].state == EntryState::EMPTY || table[index].state == EntryState::TOMBSTONE) {
                table[index].key = key;
                table[index].value = value;
                table[index].state = EntryState::OCCUPIED;
                cout << "Inserted key " << key << " at index " << index << "\n";
                return;
            }
            if (table[index].state == EntryState::OCCUPIED && table[index].key == key) {
                table[index].value = value; // update
                return;
            }
            index = (index + 1) % SIZE;
        } while (index != originalIndex);

        cout << "Hash table is full!\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        do {
            if (table[index].state == EntryState::EMPTY) {
                cout << "Key not found.\n";
                return;
            }
            if (table[index].state == EntryState::OCCUPIED && table[index].key == key) {
                table[index].state = EntryState::TOMBSTONE;
                cout << "Deleted key " << key << " at index " << index << "\n";
                return;
            }
            index = (index + 1) % SIZE;
        } while (index != originalIndex);

        cout << "Key not found.\n";
    }

    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            cout << i << ": ";
            if (table[i].state == EntryState::OCCUPIED)
                cout << "[" << table[i].key << ": " << table[i].value << "]";
            else if (table[i].state == EntryState::TOMBSTONE)
                cout << "TOMBSTONE";
            else
                cout << "EMPTY";
            cout << "\n";
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1, "One");
    ht.insert(11, "Eleven");
    ht.insert(21, "Twenty-One");

    ht.display();

    ht.remove(11);
    ht.display();

    ht.insert(11, "New Eleven");
    ht.insert(12,"Twelve");
    ht.display();

    return 0;
}
