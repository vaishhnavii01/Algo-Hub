class Solution {
    public int minCostConnectPoints(int[][] p) {
        int n = p.length;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((u, v) -> Integer.compare(u[2], v[2]));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                pq.offer(new int[] {i, j, Math.abs(p[i][0] - p[j][0]) + Math.abs(p[i][1] - p[j][1])});
        
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;  
        
        int selectedEdges = 0;
        int cost = 0;
        
        while (pq.size() > 0 || selectedEdges < n - 1) {
            int[] e = pq.poll();
            int find1 = find(e[0]);
            int find2 = find(e[1]);
            if (find1 == find2) // cycle skip edge
                continue;
            selectedEdges++;
            union(find1, find2);
            cost += e[2];
        }
        
        return cost;
    }
    
    private int[] parent;
    
    private int find(int x) {
        if (parent[x] == x)
            return x;
        return find(parent[x]);
    }

    private void union(int x, int y) {
        int u = find(x);
        int v = find(y);
        if (u != v)
            parent[u] = parent[v];
    }
}
