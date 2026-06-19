// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Check if `S[l] == S[r]`. If yes, recursively check `isPalindrome(S, l+1, r-1)`. Base case: `l >= r` returns true.

int isPalindromeHelper(string S, int l, int r) {
    if(l >= r) return 1;
    if(S[l] != S[r]) return 0;
    return isPalindromeHelper(S, l + 1, r - 1);
}
int isPalindrome(string S) {
    return isPalindromeHelper(S, 0, S.length() - 1);
}

