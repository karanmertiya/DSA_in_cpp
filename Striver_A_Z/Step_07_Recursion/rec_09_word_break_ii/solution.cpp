// Time Complexity: O(2^N)
// Space Complexity: O(2^N)
// Explanation: Backtracking. Generate all combinations. At each step, if a prefix is in dict, recursively call for the rest of the string and append the prefix to the result of the recursive call.

vector<string> solve(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
    if(memo.count(s)) return memo[s];
    if(s.empty()) return {""};
    vector<string> res;
    for(int i=1; i<=s.length(); i++) {
        string word = s.substr(0, i);
        if(dict.count(word)) {
            vector<string> rem = solve(s.substr(i), dict, memo);
            for(string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
    }
    return memo[s] = res;
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    unordered_map<string, vector<string>> memo;
    return solve(s, dict, memo);
}

