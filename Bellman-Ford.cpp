// Function to find the shortest paths from a source vertex to all other vertices using Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int V, int src) {
    // Initialize distance array with maximum values
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Print the distances from source vertex
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

