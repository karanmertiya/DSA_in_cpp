// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use two pointers, `left` starting at 0 and `right` starting at `n-1`. Skip non-alphanumeric characters. Compare the characters at `left` and `right` after converting to lowercase. If they mismatch, return false.

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right--;
        if(tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

