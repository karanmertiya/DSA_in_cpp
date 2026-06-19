// Time Complexity: O(log N)
// Space Complexity: O(log N)
// Explanation: Find largest power of 2 <= n (`x`). Bits up to `2^x - 1` are `x * 2^(x-1)`. The MSB of remaining numbers is `n - 2^x + 1`. Then recursively call for `n - 2^x`.

int largestPowerOf2inRange(int n) {
    int x = 0;
    while((1 << x) <= n) x++;
    return x - 1;
}
int countSetBits(int n) {
    if(n <= 0) return 0;
    int x = largestPowerOf2inRange(n);
    int bitsUpTo2x = x * (1 << (x - 1));
    int msbOfRest = n - (1 << x) + 1;
    int rest = n - (1 << x);
    return bitsUpTo2x + msbOfRest + countSetBits(rest);
}

