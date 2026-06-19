// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Use standard DFS. When returning from the DFS call of a node (meaning all its descendants are visited), push the node to a stack. The stack will contain the topological sort.

void dfs(int node, int vis[], stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V] = {0};
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) dfs(i, vis, st, adj);
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

