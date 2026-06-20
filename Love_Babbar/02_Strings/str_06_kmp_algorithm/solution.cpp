// Time Complexity: O(N + M)
// Space Complexity: O(M)
// Explanation: Compute the LPS (Longest Proper Prefix which is also Suffix) array for the needle. Use the LPS array to skip characters while matching with the haystack, reducing time to O(N+M).

int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;
    int m = needle.length(), n = haystack.length();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while(i < m) {
        if(needle[i] == needle[len]) lps[i++] = ++len;
        else {
            if(len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    i = 0; int j = 0;
    while(i < n) {
        if(needle[j] == haystack[i]) { i++; j++; }
        if(j == m) return i - j;
        else if(i < n && needle[j] != haystack[i]) {
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

