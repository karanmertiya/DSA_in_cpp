// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Use DFS. Maintain a visited array. Once all adjacent nodes of a vertex are visited, push the vertex to a stack. Print the stack for the topological order.

void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i=0; i<V; i++) {
        if(!vis[i]) dfs(i, vis, st, adj);
    }
    vector<int> ans;
    while(!st.empty()) { ans.push_back(st.top()); st.pop(); }
    return ans;
}

