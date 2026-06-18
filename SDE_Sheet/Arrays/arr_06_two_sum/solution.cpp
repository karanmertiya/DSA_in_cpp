// Time Complexity: O(N<sup>2</sup>) (Trade-off)
// Space Complexity: O(1)
// Explanation: Nested loops to check all possible pairs.

#include <vector>

std::vector<int> twoSumBrute(std::vector<int>& nums, int target) {
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i] + nums[j] == target) return {i, j};
        }
    }
    return {};
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use a Hash Map to store elements and their indices. Check for `target - current`.

#include <vector>
#include <unordered_map>

std::vector<int> twoSumOptimal(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];
        if(hash.find(needed) != hash.end()) {
            return {hash[needed], i};
        }
        hash[nums[i]] = i;
    }
    return {};
}

