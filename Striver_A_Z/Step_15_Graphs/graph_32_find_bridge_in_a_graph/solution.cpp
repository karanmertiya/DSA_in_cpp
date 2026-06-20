// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Remove the given edge `(c, d)` from the graph. Then run a DFS/BFS from `c`. If `d` is not reachable from `c`, then `(c, d)` was a bridge.

void dfs(int node, vector<int> adj[], vector<bool>& vis, int c, int d) {
    vis[node] = true;
    for(int nbr : adj[node]) {
        if((node == c && nbr == d) || (node == d && nbr == c)) continue;
        if(!vis[nbr]) dfs(nbr, adj, vis, c, d);
    }
}
int isBridge(int V, vector<int> adj[], int c, int d) {
    vector<bool> vis(V, false);
    dfs(c, adj, vis, c, d);
    if(!vis[d]) return 1;
    return 0;
}

