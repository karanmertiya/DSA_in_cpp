// Time Complexity: O(N^3)
// Space Complexity: O(N)
// Explanation: 1D DP array. `dp[i]` is true if string up to index `i` can be broken. Loop `i` from 1 to N, loop `j` from 0 to i. If `dp[j]` is true and `s[j...i]` is in dict, then `dp[i] = true`.

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true; break;
            }
        }
    }
    return dp[n];
}

