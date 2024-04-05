// Find operation in union-find
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation in union-find
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to construct MST using Kruskal's algorithm
void KruskalMST(vector<Edge>& edges, int V) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);
    
    // Allocate memory for subsets
    vector<Subset> subsets(V);
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    // Initialize result vector to store MST
    vector<Edge> result;
    
    int i = 0, e = 0;
    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if (x != y) {
            result.push_back(next_edge);
            unionSets(subsets, x, y);
            e++;
        }
    }
    
    // Print the MST
    cout << "Edges of MST:" << endl;
    for (auto edge : result) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }
}
