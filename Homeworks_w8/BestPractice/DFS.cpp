#include<iostream>
#include<stack>
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
    
    //Step 1: initailize stack and visited list
    stack<int> stack;
    int visitedList[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    stack.push(s);
    
    STEP2:
    //Step 2: Terminate if stack is empty
    if (stack.empty()) {
        cout << "There is no goal Node in the Graph!" << endl;
        return 0;
    }

    //Step 3: select a node from stack
    n = stack.top();
    stack.pop();

    //Step 4: Check if the selected node is the goal
    if (n == goal) {
        cout << "Goal node " << goal << " found!" << endl;
        return 0;
    }
    else {
        if (countVisitedNode >= 10) {
            cout << "Visited list is full!" << endl;
            return 0;
        }

        visitedList[countVisitedNode] = n;
        countVisitedNode++;
    }

    //Step 5: define successors node m of n
    for (int m = 0; m < 3; m++) {
        if (Graph[n][m] != 0) {
            bool alreadyVisited = false;
            // Check if the node m has already been visited
            for (int k = 0; k < countVisitedNode; k++) {
                if (visitedList[k] == m) {
                    alreadyVisited = true; //node already visited
                    break;
                }
            }
            if (!alreadyVisited) {
                stack.push(m); // push unvisited successor to stack
            }
        }
    }
    
    //Step 6: go to step 2
    goto STEP2; // Repeat the process

    return 0;
}