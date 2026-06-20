// Time Complexity: O(min(a, b))
// Space Complexity: O(1)
// Explanation: Brute Force: Iterate from 1 to min(a, b) and find the highest number that divides both.

vector<int> lcmAndGcd(int a, int b) {
    int gcd = 1;
    for(int i = 1; i <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0) gcd = i;
    }
    int lcm = (a * b) / gcd;
    return {lcm, gcd};
}

// Time Complexity: O(log(min(a, b)))
// Space Complexity: O(1)
// Explanation: Euclidean Algorithm (Optimal): Repeatedly replace max(a,b) with max(a,b) % min(a,b). The final non-zero value is the GCD. Note: LCM can be found in O(1) extra time using formula: LCM(a,b) = (a*b) / GCD(a,b)

int calcGCD(int n, int m){
    while(n > 0 && m > 0) {
        if(n > m) n = n % m;
        else m = m % n;
    }
    return (n == 0) ? m : n;
    
    // LCM Calculation
    // int lcm = (n * m) / calcGCD(n, m);
}

