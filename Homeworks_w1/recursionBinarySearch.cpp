#include <iostream>
using namespace std;

// Recursive binary search function
int recFind(int v[], int lower, int upper, int Key) {
    
    if (lower > upper) {    
        return -1; //not found
    }

    int curIn = lower + (upper - lower) / 2; // find mid
    
    if (v[curIn] == Key) {
        return curIn; //found
    }

    else if (v[curIn] > Key) {
        return recFind(v, lower, curIn - 1, Key); // search lower
    } 
    else {
        return recFind(v, curIn + 1, upper, Key); // search upper
    }
}

int main() {

    int v[] = {3, 8, 15, 23, 42, 56, 72};
    int size = sizeof(v) / sizeof(v[0]);

    int Key = 42;

    int result = recFind(v, 0, size - 1, Key);

    if (result != -1) {
        cout<< "==========================\n";
        cout << "Element found at index: " << result << endl;
        cout<< "==========================\n";

    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
