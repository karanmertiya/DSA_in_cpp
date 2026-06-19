// Time Complexity: O(E log E)
// Space Complexity: O(E + V)
// Explanation: Extract all edges as `(weight, u, v)`. Sort edges by weight. Iterate through sorted edges. Use Disjoint Set (Union-Find) to check if `u` and `v` are in the same component. If not, union them and add weight to sum.

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < V; i++) {
        for(auto& it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            edges.push_back({wt, {i, adjNode}});
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int mstWt = 0;
    for(auto& it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionByRank(u, v);
        }
    }
    return mstWt;
}

