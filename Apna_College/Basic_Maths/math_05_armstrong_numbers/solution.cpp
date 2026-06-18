// Time Complexity: O(log10(N))
// Space Complexity: O(1)
// Explanation: Extract digit count first, then mathematically sum digits raised to that count.

#include <cmath>

bool isArmstrong(int n) {
    int dup = n;
    int sum = 0;
    int digits = (int)(log10(n) + 1);
    while(n > 0) {
        int ld = n % 10;
        // Edge Case: pow() uses floats, round() ensures accuracy before int conversion
        sum += round(pow(ld, digits));
        n = n / 10;
    }
    return sum == dup;
}

