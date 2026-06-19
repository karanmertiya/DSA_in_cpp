// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
// Explanation: Use a Min Heap to store `(weight, node)`. Start from node 0. Pop min edge. If node is unvisited, add weight to sum, mark visited, and push its unvisited neighbors to the heap.

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(V, false);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int wt = it.first, node = it.second;
        if(vis[node]) continue;
        vis[node] = true;
        sum += wt;
        for(auto i : adj[node]) {
            int adjNode = i[0], edW = i[1];
            if(!vis[adjNode]) pq.push({edW, adjNode});
        }
    }
    return sum;
}

