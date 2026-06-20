// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Optimal: Iterate while storing numbers and their indices in a hash map. Check if `target - num` already exists.

#include <vector>
#include <unordered_map>
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> mpp;
    for(int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];
        if(mpp.find(needed) != mpp.end()) {
            return {mpp[needed], i};
        }
        mpp[nums[i]] = i;
    }
    return {};
}

