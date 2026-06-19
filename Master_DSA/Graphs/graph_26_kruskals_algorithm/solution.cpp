// Time Complexity: O(E log E + E * alpha)
// Space Complexity: O(V + E)
// Explanation: Sort all edges by weight. Iterate through sorted edges. Use Disjoint Set Union (DSU) to check if adding the edge forms a cycle. If not, add edge to MST and union the sets.

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
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
    for(int i=0; i<V; i++) {
        for(auto it : adj[i]) {
            int adjNode = it[0], wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int sum = 0;
    for(auto it : edges) {
        int wt = it.first, u = it.second.first, v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)) {
            sum += wt;
            ds.unionBySize(u, v);
        }
    }
    return sum;
}

