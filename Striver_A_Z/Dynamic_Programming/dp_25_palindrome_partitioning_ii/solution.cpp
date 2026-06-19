// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Front Partitioning. `dp[i]` is the minimum cuts for `s[i...n-1]`. To compute `dp[i]`, iterate `j` from `i` to `n-1`. If `s[i...j]` is a palindrome, then `cost = 1 + dp[j+1]`. `dp[i]` is the minimum of these costs. Return `dp[0] - 1`.

bool isPalindrome(string& s, int i, int j) {
    while(i < j) if(s[i++] != s[j--]) return false;
    return true;
}
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    for(int i=n-1; i>=0; i--) {
        int minCuts = INT_MAX;
        for(int j=i; j<n; j++) {
            if(isPalindrome(s, i, j)) {
                int cost = 1 + dp[j+1];
                minCuts = min(minCuts, cost);
            }
        }
        dp[i] = minCuts;
    }
    return dp[0] - 1;
}

