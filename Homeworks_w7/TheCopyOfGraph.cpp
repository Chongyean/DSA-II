#include <iostream>
using namespace std;

const int SIZE = 6;

// Graph adjacency matrix
int Graph[SIZE][SIZE] = {
    {0, 2, 0, 3, 3, 0},
    {2, 0, 4, 0, 0, 0},
    {0, 4, 0, 5, 0, 0},
    {3, 0, 5, 0, 2, 6},
    {3, 0, 0, 2, 0, 7},
    {0, 0, 0, 6, 7, 0}
};

// Option 1: Display the full graph
void displayGraph() {
    cout << "\n======= Graph Matrix =======" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}


// Option 2: Find connections of a node
void findOutConnection() {
    int node;
    cout << "Enter node number (1 - 6) to find its connections: ";
    cin >> node;
    
    if (node < 1 || node > SIZE) {
        cout << "Invalid node number." << endl;
        return;
    }
    
    int idx = node - 1; // Convert to 0-based index
    cout << "Node " << node << " has connections:" << endl;
    
    bool hasConnection = false;
    for (int i = 0; i < SIZE; i++) {
        if (Graph[idx][i] != 0) {
            cout << " -> Node " << (i + 1) << " by weight " << Graph[idx][i] << endl;
            hasConnection = true;
        }
    }
    
    if (!hasConnection) {
        cout << "No connections found for Node " << node << "." << endl;
    }
}

// Option 3: Check if node exists (1–6)
void findInConnection() {
int node;
    cout << "Enter node number (1 - 6) to find incoming connections: ";
    cin >> node;

    if (node < 1 || node > SIZE) {
        cout << "Invalid node number." << endl;
        return;
    }

    int idx = node - 1;
    cout << "Nodes that connect to Node " << node << ":" << endl;

    bool hasConnection = false;
    for (int i = 0; i < SIZE; i++) {
        if (Graph[i][idx] != 0) {
            cout << " <- Node " << (i + 1) << " by weight " << Graph[i][idx] << endl;
            hasConnection = true;
        }
    }

    if (!hasConnection) {
        cout << "No incoming connections to Node " << node << "." << endl;
    }
}


void findConnectedNodes() {
    int node;
    cout << "Enter node number (1 - 6) to find all connected nodes: ";
    cin >> node;

    if (node < 1 || node > SIZE) {
        cout << "Invalid node number." << endl;
        return;
    }

    int idx = node - 1;
    cout << "Connections related to Node " << node << ":" << endl;

    bool hasConnection = false;

    for (int i = 0; i < SIZE; i++) {
        if (Graph[idx][i] != 0) {
            if (Graph[idx][i] != 0) {
            cout << "From Node " << node << " => Node " << (i + 1)
                 << " | Weight: " << Graph[idx][i] << endl;
            hasConnection = true;
            }
        }

            // Optional: show direction and weight details
    for (int i = 0; i < SIZE; i++) {
        if (Graph[i][idx] != 0 && i != idx) {
            cout << "From Node " << (i + 1) << " => Node " << node
                 << " | Weight: " << Graph[i][idx] << endl;
            hasConnection = true;
        }
    }
        if (!hasConnection) {
        cout << "No connections found for Node " << node << "." << endl;
    }
}

}
int main() {
    int choice;

    do {
        cout << "\n======= Menu =======" << endl;
        cout << "1. Display the graph" << endl;
        cout << "2. Find Connection of Node" << endl;
        cout << "3. Find Node of Connection" << endl;
        cout << "4. Find by connected nodes" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayGraph();
                break;
            case 2:
                findOutConnection();
                break;
            case 3:
                findInConnection();
                break;
            case 4:
                findConnectedNodes();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
