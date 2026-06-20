// Time Complexity: O(E)
// Space Complexity: O(N + E)
// Explanation: Use a queue storing `(stops, node, cost)`. We don't need a priority queue because stops increase uniformly by 1. Distance array stores min cost to reach each node. Only push to queue if new cost is cheaper. If `stops > k`, skip.

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
    queue<vector<int>> q; // {stops, node, cost}
    q.push({0, src, 0});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        int stops = curr[0], node = curr[1], cost = curr[2];
        if(stops > k) continue;
        for(auto& neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;
            if(cost + edgeWeight < dist[nextNode] && stops <= k) {
                dist[nextNode] = cost + edgeWeight;
                q.push({stops + 1, nextNode, cost + edgeWeight});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

