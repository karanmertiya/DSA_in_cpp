// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
// Explanation: Standard Dijkstra's shortest path from node `k`. Return the maximum value in the distances array. If any node remains unvisited (dist == inf), return -1.

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> adj[n+1];
    for(auto t : times) adj[t[0]].push_back({t[1], t[2]});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, 1e9);
    dist[k] = 0;
    pq.push({0, k});
    while(!pq.empty()) {
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;
            if(time + wt < dist[adjNode]) {
                dist[adjNode] = time + wt;
                pq.push({time + wt, adjNode});
            }
        }
    }
    int mx = 0;
    for(int i=1; i<=n; i++) {
        if(dist[i] == 1e9) return -1;
        mx = max(mx, dist[i]);
    }
    return mx;
}

