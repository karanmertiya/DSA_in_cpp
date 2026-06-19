// Time Complexity: O(M^N)
// Space Complexity: O(N)
// Explanation: Backtracking. Try coloring each node with color 1 to m. For a color, check if any adjacent node has the same color. If safe, assign and recurse for next node. If recursion returns false, backtrack.

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for(int k=0; k<n; k++) {
        if(k != node && graph[k][node] == 1 && color[k] == col) return false;
    }
    return true;
}
bool solve(int node, int color[], int m, int n, bool graph[101][101]) {
    if(node == n) return true;
    for(int i=1; i<=m; i++) {
        if(isSafe(node, color, graph, n, i)) {
            color[node] = i;
            if(solve(node + 1, color, m, n, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = {0};
    return solve(0, color, m, n, graph);
}

