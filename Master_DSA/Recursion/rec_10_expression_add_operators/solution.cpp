// Time Complexity: O(N * 4^N)
// Space Complexity: O(N)
// Explanation: Backtracking. Keep track of the evaluated sum so far, and the previous operand (for multiplication precedence). For '*', `newSum = sum - prev + prev * curr`. Handle leading zeros.

void solve(int ind, string num, int target, vector<string>& ans, string path, long long eval, long long multed) {
    if(ind == num.size()) {
        if(eval == target) ans.push_back(path);
        return;
    }
    for(int i = ind; i < num.size(); i++) {
        if(i != ind && num[ind] == '0') break;
        string curStr = num.substr(ind, i - ind + 1);
        long long curNum = stoll(curStr);
        if(ind == 0) {
            solve(i + 1, num, target, ans, path + curStr, curNum, curNum);
        } else {
            solve(i + 1, num, target, ans, path + "+" + curStr, eval + curNum, curNum);
            solve(i + 1, num, target, ans, path + "-" + curStr, eval - curNum, -curNum);
            solve(i + 1, num, target, ans, path + "*" + curStr, eval - multed + multed * curNum, multed * curNum);
        }
    }
}
vector<string> addOperators(string num, int target) {
    vector<string> ans;
    solve(0, num, target, ans, "", 0, 0);
    return ans;
}

