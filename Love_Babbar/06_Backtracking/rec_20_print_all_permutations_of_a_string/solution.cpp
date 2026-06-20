// Time Complexity: O(N! * N)
// Space Complexity: O(N)
// Explanation: Convert string to char array and sort it. Use backtracking: pass a boolean visited array and a temporary string. If temporary string length equals original length, add to answer. Else, iterate through characters. To avoid duplicates, if `i > 0` and `s[i] == s[i-1]` and `!vis[i-1]`, skip. Otherwise, mark visited, append, recurse, unmark, pop.

void solve(string& S, vector<bool>& vis, string& curr, vector<string>& ans) {
    if(curr.length() == S.length()) {
        ans.push_back(curr);
        return;
    }
    for(int i = 0; i < S.length(); i++) {
        if(vis[i] || (i > 0 && S[i] == S[i-1] && !vis[i-1])) continue;
        vis[i] = true;
        curr.push_back(S[i]);
        solve(S, vis, curr, ans);
        curr.pop_back();
        vis[i] = false;
    }
}
vector<string> find_permutation(string S) {
    sort(S.begin(), S.end());
    vector<string> ans;
    string curr = "";
    vector<bool> vis(S.length(), false);
    solve(S, vis, curr, ans);
    return ans;
}

