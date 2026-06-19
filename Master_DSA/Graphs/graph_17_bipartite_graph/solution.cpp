// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Use BFS to color the graph with 2 colors (0 and 1). Start with a node, color it 0. All its neighbors must be colored 1, their neighbors 0, and so on. If we ever find an adjacent node with the same color, the graph is not bipartite.

bool checkBipartite(int start, vector<int> adj[], vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int nbr : adj[node]) {
            if(color[nbr] == -1) {
                color[nbr] = 1 - color[node];
                q.push(nbr);
            } else if(color[nbr] == color[node]) return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<int>adj[]){
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            if(!checkBipartite(i, adj, color)) return false;
        }
    }
    return true;
}

