#include <iostream>
using namespace std;

int main () {

    // 1. Matrices for Graph Representation
    int Graph[6][6] = {
        // 1  2  3  4  5  6
        { 0, 1, 0, 1, 1, 0 }, // 1 connects to 2, 4, 5
        { 1, 0, 1, 1, 0, 0 }, // 2 connects to 1, 3, 4
        { 0, 1, 0, 1, 0, 0 }, // 3 connects to 2, 4
        { 1, 0, 1, 0, 1, 1 }, // 4 connects to 1, 3, 5, 6
        { 1, 0, 0, 1, 0, 1 }, // 5 connects to 1, 4, 6
        { 0, 0, 0, 1, 1, 0 }  // 6 connects to 4, 5
    };
    
    int GraphLength[6][6] = {
        // 1  2  3  4  5  6
        { 0, 2, -1, 3, 3, -1 },  // 1 connects to 2, 4, 5
        { 2, 0, 4, 1, -1, -1 },  // 2 connects to 1, 3, 4
        { -1, 4, 0, 5, -1, -1 }, // 3 connects to 2, 4
        { 3, -1, 5, 0, 0, 6 },   // 4 connects to 1, 3, 5, 6
        { 3, -1, -1, 2, 0, 7 },  // 5 connects to 1, 4, 6
        { -1, -1, -1, 6, 7, 0 }  // 6 connects to 4, 5
    };

    while (true) {
    
    cout << endl;
    cout << "======== GRAPH ANALYSIS MENU =========" << endl;
    cout << "1. Find connections for a specific node" << endl;
    cout << "2. Find length between two nodes" << endl;
    cout << "3. length of node 1 -> 2 -> 4 -> 5 -> 6" << endl;
    cout << "=======================================" << endl;
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    
        switch(choice) {
            case 1: {

                cout << "Enter node to find connections ( 1 - 6 ): ";
                int userInput;
                cin >> userInput;
                
                // Check for valid input
                if (userInput < 1 || userInput > 6) {
                    cout << "Invalid node input. Please enter a number between 1 and 6." << endl;
                    return 1;
                }

                // Convert to 0-based index for array access
                int nodeIndex = userInput - 1;

                // 2.1 Find nodes connected FROM user input (outgoing connections)
                cout << "Node " << userInput << " connects to: ";
                bool hasOutgoing = false;
                for (int i = 0; i < 6; ++i) {
                    if (Graph[nodeIndex][i] != 0) {
                        cout << "Node " << (i + 1) << " ";
                        hasOutgoing = true;
                    }
                }
                if (!hasOutgoing) cout << "No outgoing connections";
                cout << endl;
                
                // 2.2 Find nodes that connect to user input (incoming connections)
                cout << "Nodes that connect TO Node " << userInput << ": ";
                bool hasIncoming = false;
                for (int i = 0; i < 6; ++i) {
                    if (Graph[i][nodeIndex] != 0) {
                        cout << "Node " << (i + 1) << " ";
                        hasIncoming = true;
                    }
                }
                if (!hasIncoming) cout << "No incoming connections";
                cout << endl;
                break;
            }
            
            case 2: {
                // Find path length between two nodes
                int startNode, endNode;
                cout << "Enter start node (1-6): ";
                cin >> startNode;
                cout << "Enter end node (1-6): ";
                cin >> endNode;
                
                if (startNode < 1 || startNode > 6 || endNode < 1 || endNode > 6) {
                    cout << "Invalid node input. Please enter numbers between 1 and 6." << endl;
                    return 1;
                }
                
                // Convert to 0-based index
                int startIndex = startNode - 1;
                int endIndex = endNode - 1;
                
                if (GraphLength[startIndex][endIndex] != -1) {
                    cout << "Length of path from Node " << startNode << " to Node " << endNode << " is: " << GraphLength[startIndex][endIndex] << endl;
                } else {
                    cout << "No direct path exists between Node " << startNode << " and Node " << endNode << "." << endl;
                }
                break;
            }
            
            case 3: {
                // find length from 1->2->4->5->6
                cout << "Length of node : 1 -> 2 -> 4 -> 5 -> 6 " << endl;
                int path[] = {0, 1, 3, 4, 5}; // 0-based indices for nodes 1,2,4,5,6
                int displayPath[] = {1, 2, 4, 5, 6}; // Display labels
                int pathSize = 5;
                int totalLength = 0;
                bool validPath = true;

                // Check if the path is valid
                for (int i = 0; i < pathSize - 1; i++) {
                    int from = path[i];
                    int to = path[i + 1];
                    
                    if (GraphLength[from][to] == -1) {
                        cout << " No connection from Node " << displayPath[i] << " to Node " << displayPath[i + 1] << endl;
                        validPath = false;
                        break;
                    }
                    
                    totalLength += GraphLength[from][to];
                    cout << " Node " << displayPath[i] << " -> Node " << displayPath[i + 1] << " ( length : " << GraphLength[from][to] << " )" << endl;
                }

                if (validPath) {
                    cout << " Total path length ( 1 -> 2 -> 4 -> 5 -> 6 ) : " << totalLength << endl;
                } else {
                    cout << " Path is invalid !" << endl;
                }
                break;
            }
            
            default:
                cout << " Invalid choice ! " << endl;
                break;
        }
    }
    
    return 0;
}