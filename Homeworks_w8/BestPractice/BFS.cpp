#include<iostream>
#include<queue>
using namespace std;

int Graph[3][3] = {
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0}
};

int main() {
    
    int s = 0;
    int goal = 2;
    int n;
    int countVisitedNode = 0;

    //Step 1: initailize queue and visited list
    queue<int> queue;
    int visitedList[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    queue.push(s);

    while (!queue.empty()) {
        //Step 2: Terminate if queue is empty
        if (queue.empty()) {
            cout << "There is no goal Node in the Graph!" << endl;
            return 0; // Exit if queue is empty
        }

        //Step 3: select a node from queue
        n = queue.front();
        queue.pop();

        //Step 4: Check if the selected node is the goal
        if (n == goal) {
            cout << "Goal node 2 found!" << endl;
            break;
        }
        else {
            if (countVisitedNode >= 10) {
                cout << "Visited list is full!" << endl;
            }

            visitedList[countVisitedNode] = n;
            countVisitedNode++;
        }

        //Step 5: define successors node m of n
        for (int m = 0; m < 3; m++) {
            if (Graph[n][m] != 0) {
                bool alreadyVisited = false;
                for (int k = 0; k < countVisitedNode; k++) {
                    if (visitedList[k] == m) {
                        alreadyVisited = true;
                        break;
                    }
                }
                if (!alreadyVisited) {
                    queue.push(m);
                }
            }
        }
    }
    //Step 6: go to step 2
    return 0;
}