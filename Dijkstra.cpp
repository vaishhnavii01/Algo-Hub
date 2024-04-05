class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        List<int[]>[] adj = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] t : times) {
            adj[t[0] - 1].add(new int[]{t[1] - 1, t[2]});
        }

        int[] dist = new int[N];
        Arrays.fill(dist, -1);

        dist[K - 1] = 0;
        Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1]));
        minHeap.offer(new int[]{K - 1, 0});

        while (minHeap.size() > 0) {
            int curr = minHeap.peek()[0];
            minHeap.poll();
            for (int[] pair : adj[curr]) {
                int next = pair[0];
                int weight = pair[1];
                int d = dist[curr] + weight;
                if (dist[next] == -1 || dist[next] > d) {
                    dist[next] = d;
                    minHeap.offer(new int[]{next, dist[next]});
                }
            }
        }

        int maxwait = 0;
        for (int i = 0; i < N; i++) {
            if(dist[i] == -1) 
                return -1;
            maxwait = Math.max(maxwait, dist[i]);
        }
        return maxwait;
    }
}
