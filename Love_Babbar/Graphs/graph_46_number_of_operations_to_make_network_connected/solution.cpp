// Time Complexity: O(E * alpha)
// Space Complexity: O(V)
// Explanation: If total edges < n - 1, return -1. Count extra edges while building DSU. If union fails (already connected), it's an extra edge. Number of operations to connect components is `components - 1`. If `extraEdges >= components - 1`, return `components - 1`.

int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n - 1) return -1;
    DisjointSet ds(n);
    int extraEdges = 0;
    for(auto& it : connections) {
        if(ds.findUPar(it[0]) == ds.findUPar(it[1])) {
            extraEdges++;
        } else {
            ds.unionByRank(it[0], it[1]);
        }
    }
    int components = 0;
    for(int i=0; i<n; i++) {
        if(ds.findUPar(i) == i) components++;
    }
    if(extraEdges >= components - 1) return components - 1;
    return -1;
}

