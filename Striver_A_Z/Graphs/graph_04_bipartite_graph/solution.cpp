// Time Complexity: O(V + E)
// Space Complexity: O(V)
// Explanation: BFS/DFS coloring approach. Color adjacent nodes with alternate colors (0 and 1). If an adjacent node has the SAME color, it's not bipartite.

#include <vector>
#include <queue>
bool isBipartite(std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> color(n, -1);
    for(int i = 0; i < n; i++) {
        if(color[i] != -1) continue;
        std::queue<int> q;
        q.push(i);
        color[i] = 0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int neighbor : graph[node]) {
                if(color[neighbor] == -1) {
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                } else if(color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

