// Time Complexity: O(M * N) (Constraint)
// Space Complexity: O(M * N) (Trade-off)
// Explanation: Tabulation (Bottom-Up). Use a 2D array where `dp[i][j]` represents the LCS of prefixes of length `i` and `j`.

#include <string>
#include <vector>
#include <algorithm>
int longestCommonSubsequence(std::string text1, std::string text2) {
    int n = text1.length(), m = text2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

