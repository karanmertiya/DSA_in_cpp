// --- Brute Force Approach ---
// Time Complexity: O(min(N1, N2)) (Trade-off)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>TLE Risk:</b> ~10<sup>9</sup> ops heavily exceeds 1 sec limit.
// Note: Iterate from min(N1, N2) down to 1. The first number dividing both is the GCD.

#include <algorithm>

int gcdBrute(int n1, int n2) {
    for(int i = min(n1, n2); i >= 1; i--) {
        if(n1 % i == 0 && n2 % i == 0) {
            return i;
        }
    }
    return 1;
}

// --- Optimal Approach ---
// Time Complexity: O(log(&Phi;)(min(N1, N2))) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Modulo Safety:</b> Euclidean Algorithm easily passes 10<sup>9</sup> via log-scale modulo operations.
// Note: Euclidean algorithm: gcd(a, b) = gcd(b, a % b) until one becomes 0.

int gcdOptimal(int a, int b) {
    while(a > 0 && b > 0) {
        // Uses modulo rather than subtraction for logarithmic time complexity
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    return a;
}

