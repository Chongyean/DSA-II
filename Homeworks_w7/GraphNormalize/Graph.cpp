#include <iostream>
using namespace std;

void displayGraph() {
    int Graph[6][6] = {
        {0, 2, 0, 3, 3, 0},
        {2, 0, 4, 0, 0, 0},
        {0, 4, 0, 5, 0, 0},
        {3, 1, 5, 0, 2, 6},
        {3, 0, 0, 2, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };

    cout << "======= Graph matrix =======" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

void findNode() {
    int Graph[6][6] = {
        {0, 2, 0, 3, 3, 0},
        {2, 0, 4, 0, 0, 0},
        {0, 4, 0, 5, 0, 0},
        {3, 1, 5, 0, 2, 6},
        {3, 0, 0, 2, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };

    int node;
    cout << "Enter the node to find: ";
    cin >> node;

    if (node < 0 || node >= 6) {
        cout << "Invalid node number." << endl;
        return;
    }

    cout << "Connections for Node " << node << " : ";
    for (int i = 0; i < 6; i++) {
        if (Graph[node][i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void findConnection() {
    int Graph[6][6] = {
        {0, 2, 0, 3, 3, 0},
        {2, 0, 4, 0, 0, 0},
        {0, 4, 0, 5, 0, 0},
        {3, 1, 5, 0, 2, 6},
        {3, 0, 0, 2, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };

    int node;
    cout << "Enter the node to find connections: ";
    cin >> node;

    if (node < 0 || node >= 6) {
        cout << "Invalid node number." << endl;
        return;
    }

    cout << "Connections for Node " << node << ": ";
    for (int i = 0; i < 6; i++) {
        if (Graph[node][i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {

    // Matrix representation of a graph
    int Graph[6][6] = {
        {0, 2, 0, 3, 3, 0},
        {2, 0, 4, 0, 0, 0},
        {0, 4, 0, 5, 0, 0},
        {3, 1, 5, 0, 2, 6},
        {3, 0, 0, 2, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };
    
    // Users options
    cout << "====================" << endl;
    cout << "1. Display the graph" << endl;
    cout << "2. Find Node" << endl;
    cout << "3. Find Connection of Node" << endl;
    cout << "4. Exit" << endl;

    cout<< "Please enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice){
    case 1:
        displayGraph();
        break;
    case 2:
        findNode();
        break;
    case 3:
        findConnection();
        break;
    case 4:
        cout << "Exiting the program." << endl;
        return 0;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
    

    return 0;
}











