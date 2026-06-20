// Time Complexity: O(2^N)
// Space Complexity: O(N)
// Explanation: First find the number of misplaced left (`rm_l`) and right (`rm_r`) parentheses. Then use backtracking to try removing `rm_l` and `rm_r` parentheses. To avoid duplicates, skip identical adjacent characters. Finally, check if the resulting string is valid.

bool isValid(string& s) {
    int count = 0;
    for(char c : s) {
        if(c == '(') count++;
        else if(c == ')') count--;
        if(count < 0) return false;
    }
    return count == 0;
}
void solve(string s, int start, int rm_l, int rm_r, vector<string>& ans) {
    if(rm_l == 0 && rm_r == 0) {
        if(isValid(s)) ans.push_back(s);
        return;
    }
    for(int i = start; i < s.length(); i++) {
        if(i != start && s[i] == s[i-1]) continue;
        if(s[i] == '(' && rm_l > 0) {
            solve(s.substr(0, i) + s.substr(i + 1), i, rm_l - 1, rm_r, ans);
        }
        else if(s[i] == ')' && rm_r > 0) {
            solve(s.substr(0, i) + s.substr(i + 1), i, rm_l, rm_r - 1, ans);
        }
    }
}
vector<string> removeInvalidParentheses(string s) {
    int rm_l = 0, rm_r = 0;
    for(char c : s) {
        if(c == '(') rm_l++;
        else if(c == ')') {
            if(rm_l > 0) rm_l--;
            else rm_r++;
        }
    }
    vector<string> ans;
    solve(s, 0, rm_l, rm_r, ans);
    return ans;
}

