// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: XOR all elements to get `A ^ B`. The rightmost set bit in `A ^ B` means A and B differ at this bit. Use this bit to partition the array into two groups and XOR elements in each group. The results are A and B.

vector<int> singleNumber(vector<int>& nums) {
    long long XOR = 0;
    for(int num : nums) XOR ^= num;
    int rightmost_set_bit = XOR & ~(XOR - 1);
    int b1 = 0, b2 = 0;
    for(int num : nums) {
        if(num & rightmost_set_bit) b1 ^= num;
        else b2 ^= num;
    }
    return {b1, b2};
}

