// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Use binary search from `1` to `num/2` or up to `46340` (sqrt of INT_MAX). If `mid * mid == num`, return true. Else if `mid * mid < num`, `low = mid + 1`. Else `high = mid - 1`.

bool isPerfectSquare(int num) {
    if(num == 1) return true;
    long long low = 1, high = num / 2;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(mid * mid == num) return true;
        else if(mid * mid < num) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

