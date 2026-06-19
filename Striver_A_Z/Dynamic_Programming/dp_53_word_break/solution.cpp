// Time Complexity: O(N * M * L) or O(N^2)
// Space Complexity: O(N)
// Explanation: `dp[i]` is true if `s[0..i-1]` can be segmented. For each `i` from 1 to `N`, try each word in dictionary. If `s[i-len(word)..i-1] == word` and `dp[i-len(word)]` is true, then `dp[i] = true`. Or iterate `j` from 0 to `i` and check if `dp[j]` is true and `s[j..i-1]` is in dict.

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    for(int i = 1; i <= s.length(); i++) {
        for(int j = 0; j < i; j++) {
            if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}

