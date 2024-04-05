class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int MAX = 1000000;
        int[][] dist = new int[N][N];
        for(int i = 0; i < N; i++)
            Arrays.fill(dist[i], MAX);
        for(int i = 0; i < N; i++)
            dist[i][i] = 0;
        for(int[] e : times)
            dist[e[0] - 1][e[1] - 1] = e[2];
        
        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++) 
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        
        int maxwait = 0;
        for(int i = 0; i < N; i++)
            maxwait = Math.max(maxwait, dist[K - 1][i]);
        return maxwait == MAX ? -1 : maxwait;
    }
}
