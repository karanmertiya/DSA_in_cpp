// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Optimal: Transpose the matrix (swap matrix[i][j] with matrix[j][i]), then reverse every row.

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) std::swap(matrix[i][j], matrix[j][i]);
    }
    for(int i=0; i<n; i++) std::reverse(matrix[i].begin(), matrix[i].end());
}

