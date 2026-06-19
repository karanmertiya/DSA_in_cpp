// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Explanation: Since a path can revisit nodes and edges, the minimum score path from 1 to `n` is simply the minimum weight edge in the connected component containing node 1 and `n`. Perform BFS/DFS from node 1 and find the minimum edge weight in the entire component.

int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for(auto& r : roads) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(1);
    vis[1] = 1;
    int minScore = INT_MAX;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(auto& neighbor : adj[node]) {
            minScore = min(minScore, neighbor.second);
            if(!vis[neighbor.first]) {
                vis[neighbor.first] = 1;
                q.push(neighbor.first);
            }
        }
    }
    return minScore;
}

