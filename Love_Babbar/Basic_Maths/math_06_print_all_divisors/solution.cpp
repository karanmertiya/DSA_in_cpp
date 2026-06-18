// Time Complexity: O(N) (Trade-off)
// Space Complexity: O(1)
// Explanation: Iterate from 1 to N sequentially, checking for divisibility.

#include <iostream>

void printDivisorsBrute(int n) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            std::cout << i << " ";
        }
    }
}

// Time Complexity: O(&radic;N * log(&radic;N)) (Constraint)
// Space Complexity: O(&radic;N) (Trade-off)
// Explanation: Iterate up to sqrt(N) to find pairs of divisors, then sort ascending.

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

