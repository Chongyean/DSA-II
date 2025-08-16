#include <iostream>
#include <stack>
using namespace std;

int Graph[ 3 ][ 3 ];

int main() {

    int s = 0; // Start node 
    int Goal = 2; // Goal node 

    stack<int> STACK; // STACK for DFS

    //VisitedList is Empty
    int VisitedList[ 10 ] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    int n;
    int CountVisitedNode = 0;

    // 1. Intialize : Set Stack = { s }, VisitedList = {  }
    STACK.push(s);
    STEP_2:

    // 2. Terminate when Stack is empty
    if (STACK.empty()) {
        cout << "No path found from node " << s << " to node " << Goal << endl;
        return 0;
    }

    else {
        cout << "BFS Traversal starting from node " << s << ":\n";
    }
    
    // 3. Select a vertex, n , from Stack
    n = STACK.top();
    STACK.pop();

    // 4. Visit n and save n to VisitedList
    if ( n == Goal ) {
        cout << "Goal node : " << Goal << " found!" << endl;
        return 0;
    }
    else {
        //check if not full
        //increase the count of visited nodes
        VisitedList[CountVisitedNode++] = n;
        cout << "Visiting node: " << n << endl;
    }

    // 5. Expand: Define Successors m of vertex n in Graph
    // For each successor, m, insert m in Stack
    // Only if m is not in VisitedList
    for ( int m = 0; m < 3; ++m ) {
        if ( Graph[ n ][ m ] != 0 ) {
            // Check if m is not already visited
            // then add to STACK
            bool alreadyVisited = false;
            for ( int i = 0; i < CountVisitedNode; ++i ) {
                if ( VisitedList[i] == m ) {
                    alreadyVisited = true;
                    break;
                }
            }
        }
    }

    goto STEP_2; // Go back to step 2

    // 6. Repeat from step 2

}