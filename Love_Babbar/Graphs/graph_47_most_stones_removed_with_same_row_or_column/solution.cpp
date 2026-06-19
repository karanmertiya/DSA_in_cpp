// Time Complexity: O(N * alpha)
// Space Complexity: O(Max(Row, Col))
// Explanation: Treat rows and columns as nodes in DSU. Connect row `x` to column `y` for each stone. Max row and max col define the size of DSU. A column node index can be `maxRow + y + 1` to separate from row indices. The answer is `total stones - number of connected components`.

int removeStones(vector<vector<int>>& stones) {
    int maxRow = 0, maxCol = 0;
    for(auto& it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_set<int> stoneNodes;
    for(auto& it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionByRank(nodeRow, nodeCol);
        stoneNodes.insert(nodeRow);
        stoneNodes.insert(nodeCol);
    }
    int components = 0;
    for(int node : stoneNodes) {
        if(ds.findUPar(node) == node) components++;
    }
    return stones.size() - components;
}

