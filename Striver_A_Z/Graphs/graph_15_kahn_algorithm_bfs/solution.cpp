// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Compute in-degrees for all nodes. Push nodes with 0 in-degree to a queue. Pop, add to answer, and reduce in-degrees of neighbors. If a neighbor reaches 0, push it.

vector<int> topoSort(int V, vector<int> adj[]) {
    int indegree[V] = {0};
    for(int i=0; i<V; i++) {
        for(auto it: adj[i]) indegree[it]++;
    }
    queue<int> q;
    for(int i=0; i<V; i++) if(indegree[i] == 0) q.push(i);
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        topo.push_back(node);
        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

