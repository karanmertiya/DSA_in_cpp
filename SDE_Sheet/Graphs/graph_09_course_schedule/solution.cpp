// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Explanation: Kahn's BFS or DFS cycle detection. Here Kahn's BFS is used. If topological sort contains all V vertices, then true.

bool canFinish(int V, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);
    for(auto it: prerequisites) {
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }
    queue<int> q;
    for(int i=0; i<V; i++) if(indegree[i] == 0) q.push(i);
    int count = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop(); count++;
        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return count == V;
}

