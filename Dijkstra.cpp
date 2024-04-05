// Dijkstra's algorithm function
void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max()); // Initialize distance array
    vector<bool> visited(n, false); // Initialize visited array
    
    // Priority queue to store vertices based on distance from the source
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    
    // Initialize distance of source vertex to itself as 0
    distance[source] = 0;
    
    // Push source vertex to priority queue
    pq.push(Vertex(source, 0));
    
    while (!pq.empty()) {
        // Extract the vertex with minimum distance from priority queue
        Vertex curr = pq.top();
        pq.pop();
        
        int u = curr.index;
        
        // If vertex is already visited, skip it
        if (visited[u]) continue;
        
        // Mark the current vertex as visited
        visited[u] = true;
        
        // Update distance of adjacent vertices of the current vertex
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            // Relaxation step
            if (distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                pq.push(Vertex(v, distance[v])); // Push updated distance to priority queue
            }
        }
    }
    
    // Print shortest distances from source to all vertices
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << "\n";
    }
}
