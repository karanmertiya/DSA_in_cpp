// Time Complexity: O(V * E)
// Space Complexity: O(V)
// Explanation: Relax all edges V-1 times. To detect a negative cycle, relax one more time; if any distance updates, there's a negative cycle.

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i=0; i<V-1; i++) {
        for(auto it: edges) {
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto it: edges) {
        int u = it[0], v = it[1], wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return {-1};
    }
    return dist;
}

