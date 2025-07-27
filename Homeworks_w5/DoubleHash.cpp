#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 200;   
const int STEP_CONSTANT = 197;  // primeNum < TABLE_SIZE

// Convert 2 letter word to a number
int getKey(const string& word) {
    return word[0] * 100 + word[1];
}

// hash function ArrayIndex
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Hash function stepSize
int hash2(int key) {
    return STEP_CONSTANT - (key % STEP_CONSTANT);
}

// Insert with double hashing
void insert(vector<string>& table, const string& word) {
    int key = getKey(word);
    int index = hash1(key);
    int step = hash2(key);

    int i = 0;
    while (!table[index].empty()) {
        i++;
        index = (index + step) % TABLE_SIZE;
    }

    table[index] = word;
    cout << "Inserted \"" << word << "\" at index " << index << "  [after " << i << " steps]\n";
}

int main() {
    vector<string> table(TABLE_SIZE, "");

    vector<string> words = {
        //ck = 107 = hugeNumber = key
        //stepConstant = 197
        "ck", "ck", "gk", "hk", "ik", "jk", "kk", "lk", "mk", "nk"
    };

    for (const string& word : words) {
        insert(table, word);
    }

    return 0;
}
