// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Calculate indegree for all nodes. Push all nodes with indegree 0 to a queue. While queue is not empty, pop a node, add it to result, and decrement indegree of all its adjacent nodes. If indegree becomes 0, push to queue.

vector<int> topoSort(int V, vector<int> adj[]) {
    int indegree[V] = {0};
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) indegree[it]++;
    }
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

