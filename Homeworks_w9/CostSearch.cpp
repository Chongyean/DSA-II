#include<iostream>
using namespace std;

int Graph[8][8] = {
    {-1, 2, -1, -1, 1, -1, -1, -1},
    {-1, -1, 1, -1, -1, 3, -1, -1},
    {-1, -1, -1, 3, -1, -1, 1, -1},
    {-1, -1, -1, -1, -1, -1, -1, 5},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, 5, -1, 1, -1},
    {-1, -1, -1, -1, -1, -1, -1, 2},
    {-1, -1, -1, -1, -1, -1, -1, -1}
};

int main() {
    int s = 0; // Start node
    int goal = 7; // Goal node
    int n = s; // Current node
    
    //Step 1: initialize OPEN{s} and visited list
    int OPEN[20];
    int OPENSize = 1;
    OPEN[0] = s;

    int visitedList[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int C[8];
    int parent[8];

    for (int i = 0; i < 8; i++) {
        C[i] = 100; // Initialize costs to infinity
        parent[i] = -1; // Initialize parents to -1
    }
    C[s] = 0; // Cost of start node is 0
    visitedList[s] = 1; // Mark start node as visited

    STEP2:
    //Step 2: terminate if OPEN is empty
    if (OPENSize == 0) {         
        cout << "No path found" << endl;
        return 0;
    }

    //Step 3: select node with the smallest cost from OPEN and save n to Visited list
    int minCost = 100;
    int idx = -1;
    for (int i = 0; i < OPENSize; i++) {
        if (C[OPEN[i]] < minCost) {
            minCost = C[OPEN[i]];
            idx = i;
        }
    }
    n = OPEN[idx];

    for (int i = idx; i < OPENSize - 1; i++) {
        OPEN[i] = OPEN[i + 1];
    }
    OPENSize--;
    visitedList[n] = 1; // Mark n as visited

    //Step 4: if n is goal then terminate with success
    if (n == goal) {
        cout << "Reach goal with cost: " << C[n] << endl;
        return 0;
    }

    //Step 5: expand the node n
    for (int m = 0; m < 8; m++) {
        if (Graph[n][m] != -1) {
            int newCost = C[n] + Graph[n][m];

            bool inOPEN = false;
            for (int k = 0; k < OPENSize; k++) {
                if (OPEN[k] == m) {
                    inOPEN = true;
                    break;
                }
            }

            if (!inOPEN && !visitedList[m]) {
                C[m] = newCost;
                parent[m] = n;
                OPEN[OPENSize] = m;
                OPENSize++;
            }

            else if (C[m] > newCost) {
                C[m] = newCost;
                parent[m] = n;

                if (visitedList[m]) {
                    visitedList[m] = 0;
                    OPEN[OPENSize] = m;
                    OPENSize++;
                }
            }
        }
    }

    //Step 6: repeat from Step 2
    goto STEP2;
    return 0;
}