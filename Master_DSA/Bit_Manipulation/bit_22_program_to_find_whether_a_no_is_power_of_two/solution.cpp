// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: If `N` is a power of 2, it has only 1 set bit. `N & (N - 1)` unsets the rightmost set bit. So if `N` is a power of 2, `N & (N - 1)` will be 0.

bool isPowerofTwo(long long n){
    if(n == 0) return false;
    return (n & (n - 1)) == 0;
}

