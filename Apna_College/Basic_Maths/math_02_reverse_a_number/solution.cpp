// Time Complexity: O(log10(N))
// Space Complexity: O(log10(N)) (Trade-off)
// Explanation: Convert to string, reverse the string, and parse back to integer.

#include <string>
#include <algorithm>

int reverseNumberBrute(int n) {
    // Edge Case: Explicitly store and remove sign before string conversion
    bool isNeg = n < 0;
    string s = to_string(abs(n));
    reverse(s.begin(), s.end());
    // Exception handling ignored for brevity in brute force
    long long res = stoll(s);
    if (res > INT_MAX) return 0;
    return isNeg ? -res : res;
}

// Time Complexity: O(log10(N))
// Space Complexity: O(1)
// Explanation: Extract digits using modulo 10 and build the reversed number mathematically.

int reverseNumberOptimal(int n) {
    int revNum = 0;
    while(n != 0) {
        int ld = n % 10;
        // Edge Case: Type-agnostic overflow check utilizing reverse operation mismatch
        int temp = revNum * 10 + ld;
        if (temp / 10 != revNum) return 0;
        revNum = temp;
        n = n / 10;
    }
    return revNum;
}

