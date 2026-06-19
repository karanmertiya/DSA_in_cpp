// Time Complexity: O(C^3) where C is number of cuts
// Space Complexity: O(C^2)
// Explanation: Sort cuts array and prepend 0, append `n`. Use MCM pattern. `dp[i][j]` is the minimum cost to cut the stick between cuts `i` and `j`. `dp[i][j] = min(cost + cuts[j+1] - cuts[i-1])`.

int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int c = cuts.size() - 2;
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for(int i=c; i>=1; i--) {
        for(int j=1; j<=c; j++) {
            if(i > j) continue;
            int mini = INT_MAX;
            for(int k=i; k<=j; k++) {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

