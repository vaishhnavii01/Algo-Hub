class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        dist[K] = 0;
        for(int i = 1; i < N; i++) {
            for(int[] e : times) {
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
        
        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = Math.max(maxwait, dist[i]);
        return maxwait == Integer.MAX_VALUE ? -1 : maxwait;
    }
}
