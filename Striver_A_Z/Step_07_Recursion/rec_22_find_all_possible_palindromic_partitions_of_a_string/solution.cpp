// Time Complexity: O(N * 2^N)
// Space Complexity: O(N)
// Explanation: Iterate through the string. Extract substring `S[ind..i]`. If it is a palindrome, add it to the current partition list and recursively call for `i+1`. When `ind == length`, push the partition list to the answer.

bool isPal(string& s) {
    int i = 0, j = s.length() - 1;
    while(i < j) if(s[i++] != s[j--]) return false;
    return true;
}
void solve(string& S, int ind, vector<string>& curr, vector<vector<string>>& ans) {
    if(ind == S.length()) {
        ans.push_back(curr);
        return;
    }
    for(int i = ind; i < S.length(); i++) {
        string sub = S.substr(ind, i - ind + 1);
        if(isPal(sub)) {
            curr.push_back(sub);
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

