// --- Brute Force Approach ---
// Time Complexity: O(log10(N)) (Trade-off)
// Space Complexity: O(log10(N)) (Trade-off)
// Edge Cases: <b>Negative Signs:</b> Reversing a string with '-' results in invalid parsing.
// Note: Convert to string, reverse the string, and parse back to integer.

#include <string>
#include <algorithm>

int reverseNumberBrute(int n) {
    // Edge Case: Explicitly store and remove sign before string conversion
    bool isNeg = n < 0;
    string s = to_string(abs(n));
    reverse(s.begin(), s.end());
    int res = stoi(s);
    return isNeg ? -res : res;
}

// --- Optimal Approach ---
// Time Complexity: O(log10(N)) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Overflow Risk:</b> Number fits in 32-bit int, but its reverse might not. Forces explicit checks.
// Note: Extract digits using modulo 10 and build the reversed number mathematically.

#include <limits.h>

int reverseNumberOptimal(int n) {
    int revNum = 0;
    while(n != 0) {
        int ld = n % 10;
        // Edge Case: Strict 32-bit overflow check before multiplication
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) return 0;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    return revNum;
}

