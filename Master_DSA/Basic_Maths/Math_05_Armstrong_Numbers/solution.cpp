// --- Optimal Approach ---
// Time Complexity: O(log10(N)) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Two-Pass Logic:</b> Requires digit count upfront before processing sum of powers.
// Note: Calculate digit count first, then mathematically extract digits and compute power sums.

#include <cmath>

bool isArmstrong(int n) {
    int dup = n;
    int sum = 0;
    int digits = (int)(log10(n) + 1);
    while(n > 0) {
        int ld = n % 10;
        // Uses floating math, convert to int safely
        sum += round(pow(ld, digits));
        n = n / 10;
    }
    return sum == dup;
}

