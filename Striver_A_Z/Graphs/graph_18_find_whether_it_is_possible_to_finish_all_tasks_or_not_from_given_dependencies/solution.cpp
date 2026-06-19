// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Explanation: This is equivalent to detecting a cycle in a directed graph. If a cycle exists, it's impossible. Use Kahn's algorithm: if the number of elements in the topological sort is not equal to `N`, then a cycle exists.

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    for(auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }
    int indegree[numCourses] = {0};
    for(int i = 0; i < numCourses; i++) {
        for(auto it : adj[i]) indegree[it]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return cnt == numCourses;
}

