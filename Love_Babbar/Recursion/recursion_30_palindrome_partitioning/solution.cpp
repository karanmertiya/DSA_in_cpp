// Time Complexity: O(N * 2^N)
// Space Complexity: O(N)
// Explanation: Iterate through the string. If a prefix is a palindrome, add it to the current partition list, and recursively partition the remaining substring. When we reach the end of the string, add the current partition to the result.

bool isPalindrome(string& s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--]) return false;
    }
    return true;
}
void solve(int ind, string& s, vector<string>& path, vector<vector<string>>& res) {
    if(ind == s.size()) {
        res.push_back(path);
        return;
    }
    for(int i = ind; i < s.size(); ++i) {
        if(isPalindrome(s, ind, i)) {
            path.push_back(s.substr(ind, i - ind + 1));
            solve(i + 1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    solve(0, s, path, res);
    return res;
}

