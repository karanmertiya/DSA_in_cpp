// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: For each character, treat it as the center of an odd-length palindrome and expand outwards. Also treat it and the next character as the center of an even-length palindrome and expand outwards. Keep track of the longest palindrome found.

string longestPalindrome(string S){
    int start = 0, maxLen = 1, n = S.length();
    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && S[l] == S[r]) {
            if(r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            l--; r++;
        }
        l = i; r = i + 1;
        while(l >= 0 && r < n && S[l] == S[r]) {
            if(r - l + 1 > maxLen) { start = l; maxLen = r - l + 1; }
            l--; r++;
        }
    }
    return S.substr(start, maxLen);
}

