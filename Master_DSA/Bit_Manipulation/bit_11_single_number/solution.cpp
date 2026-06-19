// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: XORing a number with itself gives 0. Thus, XORing all numbers in the array will cancel out all the numbers that appear twice, leaving only the single number.

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int num : nums) ans ^= num;
    return ans;
}

