#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int TOMBSTONE = -2;

class HashTable {
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int idx = hash(key);
        int start = idx;

        while (table[idx] != EMPTY && table[idx] != TOMBSTONE) {
            idx = (idx + 1) % TABLE_SIZE;
            if (idx == start) {
                cout << "Hash Table full\n";
                return;
            }
        }
        table[idx] = key;
    }

    bool search(int key) {
        int idx = hash(key);
        int start = idx;

        while (table[idx] != EMPTY) {
            if (table[idx] == key) return true;
            idx = (idx + 1) % TABLE_SIZE;
            if (idx == start) break;
        }
        return false;
    }

    void remove(int key) {
        int idx = hash(key);
        int start = idx;

        while (table[idx] != EMPTY) {
            if (table[idx] == key) {
                table[idx] = TOMBSTONE;
                return;
            }
            idx = (idx + 1) % TABLE_SIZE;
            if (idx == start) break;
        }
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == EMPTY) cout << "[ ] ";
            else if (table[i] == TOMBSTONE) cout << "[x] "; // x refer to tombstone
            else cout << "[" << table[i] << "] ";
        }
        cout << endl;
    }
};

int main() {
    HashTable ht;
    ht.insert(12);
    ht.insert(22);
    ht.insert(32);


    ht.print(); // [ ] [ ] [ ] [ ] [ ] [ ] [12] [22] [32] [ ]

    ht.remove(22);
    ht.print(); // [ ] [ ] [ ] [ ] [ ] [ ] [12] [x] [32] [ ]

    cout << "Search 32: " << (ht.search(32) ? "Found" : "Not found") << endl;
    cout << "Search 22: " << (ht.search(22) ? "Found" : "Not found") << endl;

    ht.insert(42); // Reuse Tombstone spot
    ht.print(); // [ ] [ ] [ ] [ ] [ ] [ ] [12] [42] [32] [ ]

    return 0;
}
