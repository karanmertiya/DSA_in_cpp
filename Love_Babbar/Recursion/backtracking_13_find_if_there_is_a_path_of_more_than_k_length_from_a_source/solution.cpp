// Time Complexity: O(V!)
// Space Complexity: O(V)
// Explanation: Use Backtracking to perform DFS traversal from the source. Mark the current vertex as visited, subtract the edge weight from `k`, and recursively call for all adjacent unvisited vertices. If `k <= 0`, return true. Backtrack by unmarking the vertex.

bool pathMoreThanK(int src, int k, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {
    if(k <= 0) return true;
    vis[src] = true;
    for(auto i : adj[src]) {
        int v = i.first, w = i.second;
        if(!vis[v]) {
            if(pathMoreThanK(v, k - w, adj, vis)) return true;
        }
    }
    vis[src] = false;
    return false;
}

