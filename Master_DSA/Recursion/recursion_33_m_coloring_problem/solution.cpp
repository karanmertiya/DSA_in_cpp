// Time Complexity: O(M^N)
// Space Complexity: O(N)
// Explanation: Try coloring nodes one by one. For each node, try all M colors. Check if it's safe (no adjacent node has the same color). If safe, color it and recurse to the next node. If recursion returns true, we are done. Else backtrack and try next color.

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for(int k = 0; k < n; k++) {
        if(k != node && graph[k][node] == 1 && color[k] == col) return false;
    }
    return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if(node == N) return true;
    for(int i = 1; i <= m; i++) {
        if(isSafe(node, color, graph, N, i)) {
            color[node] = i;
            if(solve(node + 1, color, m, N, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[101] = {0};
    if(solve(0, color, m, n, graph)) return true;
    return false;
}

