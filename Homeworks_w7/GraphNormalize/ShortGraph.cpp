#include <iostream>
using namespace std;

// Function to find and display nodes that connect into the target node
void findIncomingNodes(int graph[6][6], int numNodes, int targetNode) {
    cout << "Nodes that connect into Node " << targetNode + 1 << " are: ";
    bool found = false;
    for (int i = 0; i < numNodes; ++i) {
        if (graph[i][targetNode] != 0) {
            cout << i + 1 << " ";
            found = true;
        }
    }
    if (!found)
        cout << "None";
    cout << endl;
}

// Function to count how many nodes connect into the target node
int countIncomingNodes(int graph[6][6], int numNodes, int targetNode) {
    int count = 0;
    for (int i = 0; i < numNodes; ++i) {
        if (graph[i][targetNode] != 0)
            count++;
    }
    return count;
}

int main() {
    const int numNodes = 6;

    // Directed graph adjacency matrix based on your image
    int graph[numNodes][numNodes] = {
        // 1  2  3  4  5  6
        {0, 2, 0, 3, 3, 0},  // Node 1
        {0, 0, 4, 1, 0, 0},  // Node 2
        {0, 0, 0, 5, 0, 0},  // Node 3
        {0, 0, 0, 0, 2, 6},  // Node 4
        {0, 0, 0, 0, 0, 7},  // Node 5
        {0, 0, 0, 0, 0, 0}   // Node 6
    };

    int inputNode;
    cout << "Enter a node number (1 to " << numNodes << "): ";
    cin >> inputNode;

    // Input validation
    if (inputNode < 1 || inputNode > numNodes) {
        cout << "Invalid node number. Please enter a value between 1 and " << numNodes << "." << endl;
        return 1;
    }

    // Convert to 0-based index
    int targetNode = inputNode - 1;

    // Process the graph
    findIncomingNodes(graph, numNodes, targetNode);
    int total = countIncomingNodes(graph, numNodes, targetNode);
    cout << "Total nodes connected into Node " << inputNode << ": " << total << endl;

    return 0;
}
