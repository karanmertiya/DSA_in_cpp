// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: If a number N is a power of 2, it has only one set bit. Thus `N & (N - 1)` will be 0. We also check if N > 0.

bool isPowerofTwo(long long n){
    if(n == 0) return false;
    return (n & (n - 1)) == 0;
}

