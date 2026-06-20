// Time Complexity: O(N * alpha(N))
// Space Complexity: O(N)
// Explanation: Imagine rows and columns are nodes in a bipartite graph. A stone at `(r, c)` connects row `r` and column `c`. The answer is `total_stones - number_of_connected_components`. We can map cols to `col + 10001` to use a single DSU.

int removeStones(vector<vector<int>>& stones) {
    unordered_map<int, int> parent;
    int components = 0;
    function<int(int)> find = [&](int i) {
        if(parent.find(i) == parent.end()) {
            parent[i] = i;
            components++;
        }
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    };
    auto unionNodes = [&](int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if(root_u != root_v) {
            parent[root_u] = root_v;
            components--;
        }
    };
    for(auto& stone : stones) {
        unionNodes(stone[0], ~stone[1]); // ~x makes columns distinct from rows
    }
    return stones.size() - components;
}

