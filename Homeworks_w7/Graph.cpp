#include <iostream>

using namespace std;

int main() {
    // Declare a 2D array to represent the adjacency matrix of the graph
    int Graph[5][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {1, 1, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        if (Graph[ 2 ][i] != 0) {
            cout << i << " " << endl;
        }

    }

    for (int i = 0; i < 5; i++) {
        if (Graph [ 4 ][i] != 0) {
            cout << i << " ";
        }      
    }

    return 0;
}