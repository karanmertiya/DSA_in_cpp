// Time Complexity: O(4^N * N)
// Space Complexity: O(N)
// Explanation: Backtracking. Create a mapping of digit to letters. Iterate through digits, for each digit loop through its mapped letters, append to current string, and recurse.

void solve(int ind, string digits, string mapping[], string path, vector<string>& ans) {
    if(ind == digits.length()) {
        ans.push_back(path);
        return;
    }
    int number = digits[ind] - '0';
    string value = mapping[number];
    for(int i = 0; i < value.length(); i++) {
        solve(ind + 1, digits, mapping, path + value[i], ans);
    }
}
vector<string> letterCombinations(string digits) {
    if(digits.length() == 0) return {};
    vector<string> ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(0, digits, mapping, "", ans);
    return ans;
}

