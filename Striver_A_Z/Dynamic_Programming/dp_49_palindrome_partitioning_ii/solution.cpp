// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Precompute a 2D boolean array `isPal` indicating if `s[i..j]` is palindrome. Then use 1D DP `cuts[i]` indicating min cuts for `s[0..i]`. `cuts[i] = min(cuts[i], cuts[j-1] + 1)` for all `j <= i` where `isPal[j][i]` is true. If `isPal[0][i]` is true, `cuts[i] = 0`.

int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j - i <= 2 || isPal[i+1][j-1])) {
                isPal[i][j] = true;
            }
        }
    }
    vector<int> cuts(n, 0);
    for(int i = 0; i < n; i++) {
        if(isPal[0][i]) cuts[i] = 0;
        else {
            cuts[i] = i;
            for(int j = 1; j <= i; j++) {
                if(isPal[j][i]) cuts[i] = min(cuts[i], cuts[j-1] + 1);
            }
        }
    }
    return cuts[n-1];
}

