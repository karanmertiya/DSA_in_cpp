// Time Complexity: O(4^N)
// Space Complexity: O(N)
// Explanation: Iterate through the string, extracting substrings as numbers. Prevent numbers with leading zeros. Recursively try `+`, `-`, `*`. For `*`, we must subtract the previous added value, and add `prev * current_val` to maintain precedence.

void solve(int idx, string num, int target, string path, long prevNum, long currVal, vector<string>& res) {
    if(idx == num.length()) {
        if(currVal == target) res.push_back(path);
        return;
    }
    string s = "";
    long n = 0;
    for(int i = idx; i < num.length(); i++) {
        if(i > idx && num[idx] == '0') break;
        s += num[i];
        n = n * 10 + (num[i] - '0');
        if(idx == 0) {
            solve(i + 1, num, target, s, n, n, res);
        } else {
            solve(i + 1, num, target, path + "+" + s, n, currVal + n, res);
            solve(i + 1, num, target, path + "-" + s, -n, currVal - n, res);
            solve(i + 1, num, target, path + "*" + s, prevNum * n, currVal - prevNum + prevNum * n, res);
        }
    }
}
vector<string> addOperators(string num, int target) {
    vector<string> res;
    solve(0, num, target, "", 0, 0, res);
    return res;
}

