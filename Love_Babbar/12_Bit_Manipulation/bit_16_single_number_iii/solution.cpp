// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: XOR all elements to get `x ^ y`. Find the rightmost set bit in this XOR result. This bit distinguishes `x` and `y`. Iterate through array again, divide numbers into two groups based on this bit, and XOR each group. The results are `x` and `y`.

vector<int> singleNumber(vector<int>& nums) {
    long long xor_all = 0;
    for(int n : nums) xor_all ^= n;
    long long rightmost_set_bit = xor_all & -xor_all;
    int x = 0, y = 0;
    for(int n : nums) {
        if(n & rightmost_set_bit) x ^= n;
        else y ^= n;
    }
    return {x, y};
}

