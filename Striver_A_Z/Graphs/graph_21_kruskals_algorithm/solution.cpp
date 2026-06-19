// Time Complexity: O(E log E)
// Space Complexity: O(V + E)
// Explanation: Sort all edges by weight. Iterate through sorted edges, if the two vertices do not belong to the same set (using Disjoint Set Union `findParent`), add the edge to MST and `union` the two sets.

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            int adjNode = it[0], wt = it[1];
            edges.push_back({wt, {i, adjNode}});
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int mstWt = 0;
    for(auto it : edges) {
        int wt = it.first, u = it.second.first, v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}

