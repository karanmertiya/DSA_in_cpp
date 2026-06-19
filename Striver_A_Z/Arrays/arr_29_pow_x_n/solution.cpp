// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Binary Exponentiation. If n is even, `x^n = (x*x)^(n/2)`. If n is odd, `x^n = x * x^(n-1)`. Handles negative powers by computing `1 / pow(x, -n)`.

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

