// Time Complexity: O(2^N * N)
// Space Complexity: O(N)
// Explanation: Iterate over the string to pick substrings. Check if the picked substring is a palindrome. If yes, add it to current partition and recur for the remaining string. Backtrack by removing it.

bool isPalindrome(string& s, int l, int r) {
    while(l < r) {
        if(s[l++] != s[r--]) return false;
    }
    return true;
}
void solve(string& S, int idx, vector<string>& curr, vector<vector<string>>& ans) {
    if(idx == S.length()) {
        ans.push_back(curr);
        return;
    }
    for(int i = idx; i < S.length(); i++) {
        if(isPalindrome(S, idx, i)) {
            curr.push_back(S.substr(idx, i - idx + 1));
            solve(S, i + 1, curr, ans);
            curr.pop_back();
        }
    }
}
vector<vector<string>> allPalindromicPerms(string S) {
    vector<vector<string>> ans;
    vector<string> curr;
    solve(S, 0, curr, ans);
    return ans;
}

