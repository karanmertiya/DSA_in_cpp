// Time Complexity: O(min(a, b))
// Space Complexity: O(1)
// Explanation: Brute Force: Iterate from 1 to min(a, b) and find the highest number that divides both.

vector<long long> lcmAndGcd(long long a, long long b) {
    long long gcd = 1;
    for(long long i = 1; i <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0) gcd = i;
    }
    long long lcm = (a / gcd) * b; // Divide first to prevent overflow
    return {lcm, gcd};
}

// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
// Explanation: Euclidean Algorithm (Optimal): Repeatedly replace max(a,b) with max(a,b) % min(a,b). The final non-zero value is the GCD. Note: LCM can be found in O(1) extra time using formula: LCM(a,b) = (a*b) / GCD(a,b)

vector<long long> lcmAndGcd(long long a, long long b) {
    long long original_a = a, original_b = b;
    while(a > 0 && b > 0) {
        if(a > b) a = a % b;
        else b = b % a;
    }
    /* The non-zero value is the GCD. Since one of them is 0, we can just return a + b */
    long long gcd = a + b; 
    long long lcm = (original_a / gcd) * original_b; // Divide first to prevent overflow
    return {lcm, gcd};
}

