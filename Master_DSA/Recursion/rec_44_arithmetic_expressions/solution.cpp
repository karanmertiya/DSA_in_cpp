// Time Complexity: O(N * 101)
// Space Complexity: O(N * 101)
// Explanation: Use a DP table `dp[i][mod]` to store the operator used to reach remainder `mod` at index `i`. Iterate through the array, for each reachable mod from previous step, try `(mod + arr[i]) % 101`, `(mod - arr[i]) % 101`, `(mod * arr[i]) % 101`. Then backtrack from `dp[N-1][0]` to find the operators.

string arithmeticExpressions(vector<int> arr) {
    int n = arr.size();
    vector<vector<char>> dp(n, vector<char>(101, 0));
    dp[0][arr[0] % 101] = ' ';
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 101; j++) {
            if(dp[i-1][j]) {
                dp[i][(j + arr[i]) % 101] = '+';
                dp[i][(j - arr[i] % 101 + 101) % 101] = '-';
                dp[i][(j * arr[i]) % 101] = '*';
            }
        }
    }
    string res = "";
    int curr = 0;
    for(int i = n - 1; i > 0; i--) {
        char op = dp[i][curr];
        res = op + to_string(arr[i]) + res;
        for(int j = 0; j < 101; j++) {
            if(dp[i-1][j]) {
                if(op == '+' && (j + arr[i]) % 101 == curr) { curr = j; break; }
                if(op == '-' && (j - arr[i] % 101 + 101) % 101 == curr) { curr = j; break; }
                if(op == '*' && (j * arr[i]) % 101 == curr) { curr = j; break; }
            }
        }
    }
    return to_string(arr[0]) + res;
}

