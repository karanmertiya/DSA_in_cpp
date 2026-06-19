// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Start from bottom row and move upwards. `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`.

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> front = triangle[n-1];
    for(int i=n-2; i>=0; i--) {
        vector<int> cur(n, 0);
        for(int j=i; j>=0; j--) {
            cur[j] = triangle[i][j] + min(front[j], front[j+1]);
        }
        front = cur;
    }
    return front[0];
}

