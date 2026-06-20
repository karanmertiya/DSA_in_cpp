// Time Complexity: O(log(min(a,b)))
// Space Complexity: O(1)
// Explanation: Euclidean Algorithm. gcd(a, b) = gcd(b, a % b). Stop when one is 0.

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    return a == 0 ? b : a;
}

