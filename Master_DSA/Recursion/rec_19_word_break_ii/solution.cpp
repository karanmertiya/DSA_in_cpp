// Time Complexity: O(N * 2^N)
// Space Complexity: O(2^N * N)
// Explanation: Backtracking. For each index, try all possible prefixes. If prefix is in dict, recursively break the remaining string. Use memoization or DP to store answers for a substring to avoid recomputation.

unordered_map<string, vector<string>> dp;
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return helper(s, dict);
}
vector<string> helper(string s, unordered_set<string>& dict) {
    if(dp.find(s) != dp.end()) return dp[s];
    vector<string> res;
    if(dict.find(s) != dict.end()) res.push_back(s);
    for(int i=1; i<s.length(); i++) {
        string right = s.substr(i);
        if(dict.find(right) != dict.end()) {
            vector<string> left_res = helper(s.substr(0, i), dict);
            for(string l : left_res) res.push_back(l + " " + right);
        }
    }
    return dp[s] = res;
}

