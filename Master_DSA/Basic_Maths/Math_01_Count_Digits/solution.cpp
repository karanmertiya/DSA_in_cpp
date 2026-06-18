// --- Brute Force Approach ---
// Time Complexity: O(log10(N)) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Sign Edge Case:</b> Fails on N=0. Requires explicit check.
// Note: Divide by 10 continuously until N becomes 0.

int countDigitsBrute(int n) {
    // Edge Case: Handle N=0 specifically
    if (n <= 0) return 1;
    int cnt = 0;
    while(n > 0) {
        cnt++;
        n = n / 10;
    }
    return cnt;
}

// --- Better Approach ---
// Time Complexity: O(1) (Constraint)
// Space Complexity: O(log10(N)) (Trade-off)
// Edge Cases: <b>Memory Trade-off:</b> String allocation required. Avoid for strictly O(1) space constraints.
// Note: Convert number to string and return length.

int countDigitsBetter(int n) {
    // Trade-off: Allocates string memory proportional to digit count
    string s = to_string(n);
    return s.length();
}

// --- Optimal Approach ---
// Time Complexity: O(1) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Library Requirement:</b> Must use math library. Fails if standard libraries are restricted.
// Note: Use base-10 logarithm to find digit count mathematically.

#include <cmath>

int countDigitsOptimal(int n) {
    // Edge Case check for zero
    if (n <= 0) return 1;
    int cnt = (int)(log10(n) + 1);
    return cnt;
}

