// Time Complexity: O(32 * N)
// Space Complexity: O(1)
// Explanation: Count bits: For each bit position, count how many numbers have it set. If count is not divisible by 3, the single number has this bit set.

int singleNumberCount(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<32; i++) {
        int sum = 0;
        for(int num : nums) {
            if((num >> i) & 1) sum++;
        }
        if(sum % 3 != 0) ans |= (1 << i);
    }
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use bitmask magic with `ones` and `twos`. `ones` keeps track of bits that appeared exactly once. `twos` tracks bits that appeared exactly twice. When a bit appears 3 times, both `ones` and `twos` are cleared.

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for(int n : nums) {
        ones = (ones ^ n) & ~twos;
        twos = (twos ^ n) & ~ones;
    }
    return ones;
}

