// Time Complexity: O(N^2 * max_word_length)
// Space Complexity: O(N)
// Explanation: `dp[i]` is true if `s[0..i-1]` can be segmented. For each `i`, iterate `j` from 0 to `i-1`. If `dp[j]` is true and `s[j..i-1]` is in dict, then `dp[i] = true`.

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i=1; i<=n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

