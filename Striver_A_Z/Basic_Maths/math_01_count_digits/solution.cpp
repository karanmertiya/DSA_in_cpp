// Time Complexity: O(log10(N))
// Space Complexity: O(1)
// Explanation: Divide by 10 continuously until N becomes 0.

#include <cmath>

int countDigitsBrute(int n) {
    // Edge Case: 0 has 1 digit, negative numbers require abs()
    if (n == 0) return 1;
    n = abs(n);
    int cnt = 0;
    while(n > 0) {
        cnt++;
        n = n / 10;
    }
    return cnt;
}

// Time Complexity: O(1) (Constraint)
// Space Complexity: O(log10(N)) (Trade-off)
// Explanation: Convert number to string and return length.

#include <string>
#include <cmath>

int countDigitsBetter(int n) {
    if (n == 0) return 1;
    // Trade-off: Allocates string memory
    string s = to_string(abs(n));
    return s.length();
}

// Time Complexity: O(1) (Constraint)
// Space Complexity: O(1)
// Explanation: Use base-10 logarithm to find digit count mathematically.

#include <cmath>

int countDigitsOptimal(int n) {
    if (n == 0) return 1;
    n = abs(n);
    int cnt = (int)(log10(n) + 1);
    return cnt;
}

