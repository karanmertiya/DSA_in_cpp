// Time Complexity: O(E log V)
// Space Complexity: O(N + E)
// Explanation: Find shortest path from source node `k` to all other nodes using Dijkstra's algorithm. The answer is the maximum distance among all nodes. If any node is unreachable (distance is infinity), return -1.

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for(auto& t : times) {
        adj[t[0]].push_back({t[1], t[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;
    pq.push({0, k});
    while(!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int d = it.first, node = it.second;
        if(d > dist[node]) continue;
        for(auto& neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int wt = neighbor.second;
            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    int maxDelay = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == 1e9) return -1;
        maxDelay = max(maxDelay, dist[i]);
    }
    return maxDelay;
}

