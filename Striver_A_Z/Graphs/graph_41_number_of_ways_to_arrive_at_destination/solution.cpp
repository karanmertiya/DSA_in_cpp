// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
// Explanation: Modify Dijkstra's. Keep `dist` array and `ways` array. When relaxing an edge: if `curr_dist + weight < dist[neighbor]`, update `dist`, push to PQ, and `ways[neighbor] = ways[curr_node]`. If `curr_dist + weight == dist[neighbor]`, `ways[neighbor] = (ways[neighbor] + ways[curr_node]) % MOD`.

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto& r : roads) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n, 1e18);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    int mod = 1e9 + 7;
    while(!pq.empty()) {
        long long d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(d > dist[node]) continue;
        for(auto& it : adj[node]) {
            int adjNode = it.first;
            long long edW = it.second;
            if(d + edW < dist[adjNode]) {
                dist[adjNode] = d + edW;
                ways[adjNode] = ways[node];
                pq.push({d + edW, adjNode});
            } else if(d + edW == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1];
}

