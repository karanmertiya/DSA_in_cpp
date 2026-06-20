// Time Complexity: O(N! / (N-K)!)
// Space Complexity: O(N)
// Explanation: Use backtracking to try swapping each digit with every digit that appears after it and is greater than it. Keep track of the maximum string seen so far. Prune if swaps == 0.

void solve(string str, int k, string& maxStr, int idx) {
    if(k == 0 || idx == str.length() - 1) return;
    char maxChar = str[idx];
    for(int i = idx + 1; i < str.length(); i++) {
        if(maxChar < str[i]) maxChar = str[i];
    }
    if(maxChar != str[idx]) k--;
    for(int i = str.length() - 1; i >= idx; i--) {
        if(str[i] == maxChar) {
            swap(str[idx], str[i]);
            if(str > maxStr) maxStr = str;
            solve(str, k, maxStr, idx + 1);
            swap(str[idx], str[i]);
        }
    }
}
string findMaximumNum(string str, int k) {
    string maxStr = str;
    solve(str, k, maxStr, 0);
    return maxStr;
}

