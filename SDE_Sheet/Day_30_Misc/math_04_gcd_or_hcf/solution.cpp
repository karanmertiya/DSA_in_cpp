// Time Complexity: O(min(a, b))
// Space Complexity: O(1)
// Explanation: Brute Force: Iterate from 1 to min(a, b) and find the highest number that divides both.

int gcd(int a, int b) {
    int ans = 1;
    for(int i = 1; i <= min(a, b); i++) {
        if(a % i == 0 && b % i == 0) ans = i;
    }
    return ans;
}

// Time Complexity: O(log(min(a,b)))
// Space Complexity: O(1)
// Explanation: Optimal: Euclidean Algorithm. gcd(a, b) = gcd(b, a % b).

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    return a == 0 ? b : a;
}

