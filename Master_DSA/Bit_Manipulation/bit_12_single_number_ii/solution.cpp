// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain two variables, `ones` and `twos`. `ones` keeps track of bits appearing once, `twos` tracks bits appearing twice. When a bit appears a third time, it is cleared from both. Update logic: `ones = (ones ^ num) & ~twos`, `twos = (twos ^ num) & ~ones`.

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for(int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}

