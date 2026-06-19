// Time Complexity: O(V * E)
// Space Complexity: O(V)
// Explanation: Use Bellman Ford algorithm. Relax all edges V-1 times. Then relax one more time. If any shortest path distance updates in the V-th relaxation, it means there is a negative weight cycle.

int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
    vector<int> dist(n, 1e8);
    dist[0] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(auto edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return 1;
    }
    return 0;
}

