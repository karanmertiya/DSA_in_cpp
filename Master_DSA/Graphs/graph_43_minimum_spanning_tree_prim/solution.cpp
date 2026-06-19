// Time Complexity: O(E log V)
// Space Complexity: O(E + V)
// Explanation: Start from node 0. Push `(0, 0)` -> `(weight, node)` into PQ. Maintain `visited` array. Pop min edge. If not visited, mark visited, add weight to sum. Traverse its neighbors; if not visited, push to PQ.

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(vis[node]) continue;
        vis[node] = 1;
        sum += wt;
        for(auto& neighbor : adj[node]) {
            int adjNode = neighbor[0];
            int edW = neighbor[1];
            if(!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

