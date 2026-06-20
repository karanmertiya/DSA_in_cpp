// Time Complexity: O(N * M)
// Space Complexity: O(1)
// Explanation: Optimal: Use the first row and first column as marker arrays to save space. We need a separate variable for the first column (or row) to avoid overlapping states.

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size(), col0 = 1;
    for(int i=0; i<n; i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j=1; j<m; j++)
            if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=1; j--)
            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        if(col0 == 0) matrix[i][0] = 0;
    }
}

