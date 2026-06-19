// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: 1. XOR all elements to get `x ^ y`. 2. Find the rightmost set bit in `x ^ y` using `(x ^ y) & -(x ^ y)`. 3. Divide elements into two groups based on this bit. 4. XOR elements in each group to get `x` and `y`.

vector<int> singleNumber(vector<int> nums) {
    long long XOR = 0;
    for(int n : nums) XOR ^= n;
    long long rightmost_set_bit = XOR & ~(XOR - 1);
    int x = 0, y = 0;
    for(int n : nums) {
        if(n & rightmost_set_bit) x ^= n;
        else y ^= n;
    }
    if(x > y) swap(x, y);
    return {x, y};
}

