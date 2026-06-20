// Time Complexity: O(2^N)
// Space Complexity: O(N)
// Explanation: Iterate from current index. For each prefix, if it is in the dictionary, add it to the current sentence string, add a space, and recur for the suffix. If we reach the end of the string, add the current sentence to the answer.

void solve(string& s, int idx, string curr, unordered_set<string>& dict, vector<string>& ans) {
    if(idx == s.length()) {
        curr.pop_back(); // Remove last space
        ans.push_back(curr);
        return;
    }
    for(int i = idx; i < s.length(); i++) {
        string word = s.substr(idx, i - idx + 1);
        if(dict.find(word) != dict.end()) {
            solve(s, i + 1, curr + word + " ", dict, ans);
        }
    }
}
vector<string> wordBreak(int n, vector<string>& dict, string s) {
    unordered_set<string> st(dict.begin(), dict.end());
    vector<string> ans;
    solve(s, 0, "", st, ans);
    return ans;
}

