// Time Complexity: O(2^(M+N))
// Space Complexity: O(M+N)
// Explanation: Use simple DFS from top-left. From cell (i, j), we can move to (i+1, j) or (i, j+1). Keep track of the path elements in an array/list. When reaching bottom-right, print/save the path.

void findPaths(vector<vector<int>>& mat, int i, int j, vector<int>& path, vector<vector<int>>& ans) {
    if(i == mat.size() - 1 && j == mat[0].size() - 1) {
        path.push_back(mat[i][j]);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(mat[i][j]);
    if(i + 1 < mat.size()) findPaths(mat, i + 1, j, path, ans);
    if(j + 1 < mat[0].size()) findPaths(mat, i, j + 1, path, ans);
    path.pop_back();
}

