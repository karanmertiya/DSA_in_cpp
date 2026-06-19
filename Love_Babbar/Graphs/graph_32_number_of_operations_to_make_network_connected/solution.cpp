// Time Complexity: O(E * alpha(N))
// Space Complexity: O(N)
// Explanation: If total edges < n - 1, impossible. Use DSU to count number of connected components `C` and number of extra edges `E`. An edge is extra if `find(u) == find(v)`. We need `C - 1` edges to connect `C` components. Since total edges >= n - 1, we guaranteed have enough extra edges. Answer is `C - 1`.

int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n - 1) return -1;
    vector<int> parent(n);
    for(int i=0; i<n; i++) parent[i] = i;
    function<int(int)> find = [&](int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    };
    int components = n;
    for(auto& edge : connections) {
        int u = find(edge[0]);
        int v = find(edge[1]);
        if(u != v) {
            parent[u] = v;
            components--;
        }
    }
    return components - 1;
}

