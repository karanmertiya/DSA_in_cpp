// Time Complexity: O(min(a, b)) (Trade-off)
// Space Complexity: O(1)
// Explanation: Iterate from min(a,b) down to 1 for GCD. Compute LCM normally.

#include <algorithm>
#include <iostream>

void gcdLcmBrute(long long a, long long b) {
    long long gcd = 1;
    for(long long i = std::min(a, b); i >= 1; i--) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }
    // Edge Case: Divide first to strictly avoid mathematical overflow
    long long lcm = (a / gcd) * b;
    std::cout << "GCD: " << gcd << ", LCM: " << lcm << "\n";
}

// Time Complexity: O(log(&Phi;)(min(a, b))) (Constraint)
// Space Complexity: O(1)
// Explanation: Euclidean algorithm for GCD: gcd(a,b) = gcd(b, a%b). Then calculate LCM.

#include <iostream>

void gcdLcmOptimal(long long a, long long b) {
    long long original_a = a, original_b = b;
    while(a > 0 && b > 0) {
        // Euclidean logic using modulo for massive performance gain
        if(a > b) a = a % b;
        else b = b % a;
    }
    long long gcd = (a == 0) ? b : a;
    long long lcm = (original_a / gcd) * original_b;
    std::cout << "GCD: " << gcd << ", LCM: " << lcm << "\n";
}

