// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Similar to minimum path sum, but we can fall diagonally. Space optimize by using previous row.

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev = matrix[0];
    for(int i=1; i<n; i++) {
        vector<int> cur(n, 0);
        for(int j=0; j<n; j++) {
            int up = matrix[i][j] + prev[j];
            int ld = matrix[i][j] + (j>0 ? prev[j-1] : 1e9);
            int rd = matrix[i][j] + (j<n-1 ? prev[j+1] : 1e9);
            cur[j] = min({up, ld, rd});
        }
        prev = cur;
    }
    int mini = 1e9;
    for(int j=0; j<n; j++) mini = min(mini, prev[j]);
    return mini;
}

