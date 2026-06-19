// Time Complexity: O(N * 2^N)
// Space Complexity: O(N * 2^N)
// Explanation: Iterate through all possible prefixes. If a prefix exists in the wordDict, recursively solve for the remaining suffix. Backtrack by appending the current prefix to the results of the suffix.

void solve(int ind, string s, unordered_set<string>& dict, string path, vector<string>& res) {
    if(ind == s.length()) {
        path.pop_back();
        res.push_back(path);
        return;
    }
    string temp = "";
    for(int i = ind; i < s.length(); i++) {
        temp += s[i];
        if(dict.find(temp) != dict.end()) {
            solve(i + 1, s, dict, path + temp + " ", res);
        }
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<string> res;
    solve(0, s, dict, "", res);
    return res;
}

