// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Brute Force: Loop n times and multiply ans by x.

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if(nn < 0) nn = -1 * nn;
    for(int i = 0; i < nn; i++) {
        ans *= x;
    }
    return n < 0 ? 1.0 / ans : ans;
}

// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Optimal: Binary Exponentiation. If n is even, x = x*x, n = n/2. If odd, ans = ans*x, n = n-1.

double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if(nn < 0) nn = -1 * nn;
    while(nn > 0) {
        if(nn % 2 == 1) {
            ans = ans * x;
            nn = nn - 1;
        } else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if(n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

