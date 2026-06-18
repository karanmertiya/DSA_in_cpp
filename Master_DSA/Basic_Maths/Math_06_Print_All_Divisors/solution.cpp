// --- Brute Force Approach ---
// Time Complexity: O(N) (Trade-off)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>TLE Risk:</b> N=10^6 takes ~10<sup>6</sup> ops. Highly inefficient compared to optimal.
// Note: Iterate from 1 to N and check for divisibility.

#include <iostream>

void printDivisorsBrute(int n) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            std::cout << i << " ";
        }
    }
}

// --- Optimal Approach ---
// Time Complexity: O(&radic;N * log(&radic;N)) (Constraint)
// Space Complexity: O(&radic;N) (Trade-off)
// Edge Cases: <b>Perfect Squares:</b> Checking `(n / i) != i` explicitly prevents duplicate divisor entries.
// Note: Iterate up to sqrt(N) to find pairs of divisors, then sort.

#include <iostream>
#include <vector>
#include <algorithm>

void printDivisorsOptimal(int n) {
    std::vector<int> divisors;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            // Edge Case: Avoid duplicate addition for perfect square roots
            if((n / i) != i) {
                divisors.push_back(n / i);
            }
        }
    }
    std::sort(divisors.begin(), divisors.end());
    for(auto it : divisors) {
        std::cout << it << " ";
    }
}

