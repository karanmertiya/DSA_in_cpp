// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Use Kahn's Algorithm. All nodes with indegree 0 take 1 unit of time. For other nodes `V`, when they are pushed to the queue from `U`, their time is `time[U] + 1`.

vector<int> minimumTime(int n, vector<vector<int>>& edges, int m) {
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1, 0);
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            ans[i] = 1;
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                ans[it] = ans[node] + 1;
                q.push(it);
            }
        }
    }
    ans.erase(ans.begin());
    return ans;
}

