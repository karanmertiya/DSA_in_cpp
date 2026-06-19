// Time Complexity: O(N^2 * L)
// Space Complexity: O(N)
// Explanation: Use a helper function `solve(index)` that returns true if substring `s[index...]` can be segmented. Try all possible prefixes from `index`. If `s[index...i]` is in dict, recursively call `solve(i+1)`. Use memoization.

int solve(int ind, string& A, unordered_set<string>& dict, vector<int>& memo) {
    if(ind == A.length()) return 1;
    if(memo[ind] != -1) return memo[ind];
    for(int i = ind; i < A.length(); i++) {
        string prefix = A.substr(ind, i - ind + 1);
        if(dict.find(prefix) != dict.end()) {
            if(solve(i + 1, A, dict, memo)) return memo[ind] = 1;
        }
    }
    return memo[ind] = 0;
}
int wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict(B.begin(), B.end());
    vector<int> memo(A.length(), -1);
    return solve(0, A, dict, memo);
}

