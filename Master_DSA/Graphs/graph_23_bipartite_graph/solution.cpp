// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: Try to color the graph using 2 colors. Use BFS/DFS. For every unvisited node, color it 0. For its neighbors, color them opposite (1). If a neighbor is already colored with the SAME color, it's not bipartite.

bool check(int start, int V, vector<int> adj[], int color[]) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = !color[node];
                q.push(it);
            } else if(color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int>adj[]) {
    int color[V];
    for(int i = 0; i < V; i++) color[i] = -1;
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            if(check(i, V, adj, color) == false) return false;
        }
    }
    return true;
}

