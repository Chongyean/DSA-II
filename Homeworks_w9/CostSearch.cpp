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
    
    //Step 1: initialize open{s} and visited list
    int open[20];
    int openSize = 1;
    open[0] = s;

    int visitedList[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int C[8];
    int parent[8];

    for (int i = 0; i < 8; i++) {
        C[i] = INT_MAX; // Initialize costs to infinity
        parent[i] = -1; // Initialize parents to -1
    }
    C[s] = 0; // Cost of start node is 0
    visitedList[s] = 1; // Mark start node as visited

    STEP2:
    //Step 2: terminate if open is empty
    if (openSize == 0) {
        cout << "No path found" << endl;
        return 0;
    }

    //Step 3: select node with the smallest cost from OPEN and save n to Visited list
    int minCost = INT_MAX;
    int idx = -1;
    for (int i = 0; i < openSize; i++) {
        if (C[open[i]] < minCost) {
            minCost = C[open[i]];
            idx = i;
        }
    }
    n = open[idx];

    for (int i = idx; i < openSize - 1; i++) {
        open[i] = open[i + 1];
    }
    openSize--;
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

            bool inOpen = false;
            for (int k = 0; k < openSize; k++) {
                if (open[k] == m) {
                    inOpen = true;
                    break;
                }
            }

            if (!inOpen && !visitedList[m]) {
                C[m] = newCost;
                parent[m] = n;
                open[openSize] = m;
                openSize++;
            }

            else if (C[m] > newCost) {
                C[m] = newCost;
                parent[m] = n;

                if (visitedList[m]) {
                    visitedList[m] = 0;
                    open[openSize] = m;
                    openSize++;
                }
            }
        }
    }

    //Step 6: repeat from Step 2
    goto STEP2;
    return 0;
}