// Time Complexity: O(log N)
// Space Complexity: O(log N) recursive stack
// Explanation: If n is even, `pow(x, n) = pow(x*x, n/2)`. If n is odd, `pow(x, n) = x * pow(x, n-1)`. Handle negative n by making it positive and returning `1 / ans`.

double myPow(double x, int n) {
    long long nn = n;
    if(nn < 0) nn = -1 * nn;
    double ans = 1.0;
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

