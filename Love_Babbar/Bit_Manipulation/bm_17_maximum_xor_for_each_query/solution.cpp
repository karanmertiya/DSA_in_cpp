// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: The maximum possible value is `(1 << maximumBit) - 1`. If current running XOR is `curr`, we want `k` such that `curr ^ k = max_val`. Thus `k = curr ^ max_val`. Do this iteratively backwards.

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int curr = 0;
    for(int n : nums) curr ^= n;
    int max_val = (1 << maximumBit) - 1;
    vector<int> ans;
    for(int i=nums.size()-1; i>=0; i--) {
        ans.push_back(curr ^ max_val);
        curr ^= nums[i];
    }
    return ans;
}

