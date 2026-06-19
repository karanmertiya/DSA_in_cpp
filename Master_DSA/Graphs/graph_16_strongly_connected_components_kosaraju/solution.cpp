// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Explanation: 1. Perform DFS and push nodes to stack upon finish (topological sort order). 2. Reverse all edges of the graph. 3. Pop nodes from stack and perform DFS on the reversed graph. Each DFS call gives one Strongly Connected Component.

void dfs1(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for(int nbr : adj[node]) if(!vis[nbr]) dfs1(nbr, adj, vis, st);
    st.push(node);
}
void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& vis) {
    vis[node] = true;
    for(int nbr : revAdj[node]) if(!vis[nbr]) dfs2(nbr, revAdj, vis);
}
int kosaraju(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    stack<int> st;
    for(int i = 0; i < V; i++) if(!vis[i]) dfs1(i, adj, vis, st);
    vector<vector<int>> revAdj(V);
    for(int i = 0; i < V; i++) {
        vis[i] = false;
        for(int nbr : adj[i]) revAdj[nbr].push_back(i);
    }
    int scc = 0;
    while(!st.empty()) {
        int node = st.top(); st.pop();
        if(!vis[node]) {
            dfs2(node, revAdj, vis);
            scc++;
        }
    }
    return scc;
}

