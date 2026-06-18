// Time Complexity: O(log10(N))
// Space Complexity: O(log10(N)) (Trade-off)
// Explanation: Convert the number to a string and compare it with its reversed version.

#include <string>
#include <algorithm>

bool isPalindromeBrute(int n) {
    string s1 = to_string(n);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

// Time Complexity: O(log10(N))
// Space Complexity: O(1)
// Explanation: Reverse the number mathematically and compare it to the original.

bool isPalindromeOptimal(int n) {
    // Edge Case: Negative numbers are strictly not palindromes
    if (n < 0) return false;
    
    int dup = n;
    long long revNum = 0;
    while(n > 0) {
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    return dup == revNum;
}

