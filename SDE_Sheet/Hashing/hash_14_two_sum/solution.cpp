// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a hash map to store `value -> index`. Iterate through array, check if `target - nums[i]` exists in map. If yes, return current index and mapped index. Else, store current value and index.

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        if(m.find(target - nums[i]) != m.end()) {
            return {m[target - nums[i]], i};
        }
        m[nums[i]] = i;
    }
    return {};
}

