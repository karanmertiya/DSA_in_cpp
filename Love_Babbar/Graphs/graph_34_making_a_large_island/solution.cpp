// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Step 1: Use DSU to connect all adjacent 1s and calculate the size of each component. Step 2: For each 0, check its 4 neighbors. Find the unique roots of those neighbors. The potential new island size is `1 + sum(size[root])` for each unique root. Find max potential size. Handle case where matrix is all 1s.

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
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
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            if(grid[r][c] == 0) continue;
            for(int i=0; i<4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1) {
                    int nodeNo = r * n + c;
                    int adjNodeNo = nr * n + nc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    int mx = 0;
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            if(grid[r][c] == 1) continue;
            set<int> components;
            for(int i=0; i<4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1) {
                    components.insert(ds.findUPar(nr * n + nc));
                }
            }
            int sizeTotal = 0;
            for(auto it : components) sizeTotal += ds.size[it];
            mx = max(mx, sizeTotal + 1);
        }
    }
    for(int cell=0; cell<n*n; cell++) mx = max(mx, ds.size[ds.findUPar(cell)]);
    return mx;
}

