#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];
bool visited[MAX];

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

int main() {
    int nodes = 6;

    // Sample Graph (Undirected)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1, 5};
    adj[5] = {2, 4};

    cout << "DFS Traversal starting from node 0:\n";
    DFS(0);

    return 0;
}
