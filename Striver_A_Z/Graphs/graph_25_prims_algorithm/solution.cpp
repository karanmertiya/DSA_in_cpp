// Time Complexity: O(E log V)
// Space Complexity: O(V)
// Explanation: Same as previous. Min Heap of `{weight, node}`.

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int wt = it.first, node = it.second;
        if(vis[node]) continue;
        vis[node] = 1;
        sum += wt;
        for(auto vec : adj[node]) {
            int adjNode = vec[0], edW = vec[1];
            if(!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

