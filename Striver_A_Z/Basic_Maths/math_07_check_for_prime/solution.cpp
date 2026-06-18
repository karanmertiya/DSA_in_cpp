// Time Complexity: O(N) (Trade-off)
// Space Complexity: O(1)
// Explanation: Iterate from 2 to N-1 and check divisibility.

bool checkPrimeBrute(int n) {
    if (n <= 1) return false;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// Time Complexity: O(&radic;N) (Constraint)
// Space Complexity: O(1)
// Explanation: Iterate from 2 up to sqrt(N) checking divisor pairs.

bool checkPrimeOptimal(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    // Edge Case Optimization: Halve range by skipping evens
    if(n % 2 == 0) return false;
    // Edge Case Optimization: Avoid floating point sqrt overhead by squaring i
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

