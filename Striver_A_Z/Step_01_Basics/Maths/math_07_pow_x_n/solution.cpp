// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Use binary exponentiation. Initialize `ans = 1.0`. Keep a copy of `n` as a long long `nn`. If `nn < 0`, make it positive. While `nn > 0`, if `nn % 2 == 1`, multiply `ans` by `x` and decrement `nn`. Otherwise, square `x` and halve `nn`. If original `n < 0`, return `1.0 / ans`.

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

