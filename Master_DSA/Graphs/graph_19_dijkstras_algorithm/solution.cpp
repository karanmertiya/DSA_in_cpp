// Time Complexity: O(E log V)
// Space Complexity: O(V)
// Explanation: Initialize distances to infinity, and source distance to 0. Use a Min Heap (priority queue) to store `{dist, vertex}`. Pop the vertex with min distance, and relax its neighbors. If a shorter path is found to a neighbor, push it to the queue.

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]) {
            int v = it[0];
            int wt = it[1];
            if(d + wt < dist[v]) {
                dist[v] = d + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

