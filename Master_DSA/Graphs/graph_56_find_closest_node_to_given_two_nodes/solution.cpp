// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Run BFS from `node1` to get `dist1` array, and BFS from `node2` to get `dist2` array. Then iterate through all nodes `0` to `n-1`. For nodes reachable from both, compute `max(dist1[i], dist2[i])`. Return the node that minimizes this maximum distance. On tie, return the smallest index.

void bfs(int start, vector<int>& edges, vector<int>& dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        int next = edges[node];
        if(next != -1 && dist[next] == 1e9) {
            dist[next] = dist[node] + 1;
            q.push(next);
        }
    }
}
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, 1e9), dist2(n, 1e9);
    bfs(node1, edges, dist1);
    bfs(node2, edges, dist2);
    int minDist = 1e9, ans = -1;
    for(int i = 0; i < n; i++) {
        if(dist1[i] != 1e9 && dist2[i] != 1e9) {
            int maxD = max(dist1[i], dist2[i]);
            if(maxD < minDist) {
                minDist = maxD;
                ans = i;
            }
        }
    }
    return ans;
}

