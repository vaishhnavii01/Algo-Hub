#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int V = graph.size();
    vector<bool> visited(V, false);
    
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    // Example graph representation using adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Neighbors of vertex 0
        {0, 3, 4},  // Neighbors of vertex 1
        {0, 5},     // Neighbors of vertex 2
        {1},        // Neighbors of vertex 3
        {1},        // Neighbors of vertex 4
        {2}         // Neighbors of vertex 5
    };

    cout << "BFS traversal starting from vertex 0: ";
    bfs(graph, 0); // Start BFS traversal from vertex 0
    cout << endl;

    return 0;
}
