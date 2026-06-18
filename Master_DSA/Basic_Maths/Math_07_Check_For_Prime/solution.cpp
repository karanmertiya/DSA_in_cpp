// --- Brute Force Approach ---
// Time Complexity: O(N) (Trade-off)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>TLE Guarantee:</b> N=10^9 takes ~10<sup>9</sup> ops. Guaranteed TLE on any modern platform.
// Note: Iterate from 2 to N-1 and check divisibility.

bool checkPrimeBrute(int n) {
    if (n <= 1) return false;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// --- Optimal Approach ---
// Time Complexity: O(&radic;N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Loop Optimization:</b> `i * i <= n` is far superior to computing `sqrt(n)` repeatedly.
// Note: Iterate from 2 up to sqrt(N) since divisors come in pairs.

bool checkPrimeOptimal(int n) {
    if(n <= 1) return false;
    // Edge Case Optimization: Avoid floating point sqrt overhead by squaring i
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

