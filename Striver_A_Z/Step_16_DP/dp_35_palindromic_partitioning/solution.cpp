// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Create a `dp` array where `dp[i]` is min cuts for `str[0..i]`. Also use a 2D boolean DP to check if `str[j..i]` is a palindrome. If it is, `dp[i] = min(dp[i], dp[j-1] + 1)`.

int palindromicPartition(string str) {
    int n = str.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) {
        int minCut = i;
        for(int j = 0; j <= i; j++) {
            if(str[i] == str[j] && (i - j < 2 || isPal[j+1][i-1])) {
                isPal[j][i] = true;
                if(j == 0) minCut = 0;
                else minCut = min(minCut, dp[j-1] + 1);
            }
        }
        dp[i] = minCut;
    }
    return dp[n-1];
}

