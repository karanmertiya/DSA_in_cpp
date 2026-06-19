// Time Complexity: O(E log V)
// Space Complexity: O(V)
// Explanation: Min-heap (priority queue) to repeatedly extract the node with the minimum distance and relax its neighbors.

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    pq.push({0, S});
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]) {
            int adjNode = it[0], weight = it[1];
            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

