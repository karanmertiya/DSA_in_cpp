// Time Complexity: O(2^N)
// Space Complexity: O(N) recursion stack
// Explanation: Use recursion. At each character, you have two choices: either include it in the current subsequence or exclude it. When you reach the end of the string, print/store the formed subsequence.

void solve(string s, string curr, int i, vector<string>& res) {
    if(i == s.length()) {
        if(curr != "") res.push_back(curr);
        return;
    }
    solve(s, curr, i + 1, res);
    solve(s, curr + s[i], i + 1, res);
}
vector<string> allSubsequences(string s) {
    vector<string> res;
    solve(s, "", 0, res);
    return res;
}

