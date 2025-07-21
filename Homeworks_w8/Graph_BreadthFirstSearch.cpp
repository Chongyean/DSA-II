#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function
void bfs(int start, vector<vector<int>>& graph, int nodes) {
    vector<bool> visited(nodes, false); // Keep track of visited nodes
    queue<int> q; // Queue for BFS

    // Step 1: Start from the given node
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    // Step 2–6: Loop
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Step 5: Look at all neighbors
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Main function
int main() {
    int nodes = 6;
    
    // Representing the graph (0-based index)
    vector<vector<int>> graph(nodes);

    // Example edges
    graph[0] = {1, 3, 4};
    graph[1] = {0, 2};
    graph[2] = {1, 3};
    graph[3] = {0, 2, 5};
    graph[4] = {0};
    graph[5] = {3};

    int startNode;
    cout << "Enter starting node (0 to " << nodes - 1 << "): ";
    cin >> startNode;

    bfs(startNode, graph, nodes);

    return 0;
}
