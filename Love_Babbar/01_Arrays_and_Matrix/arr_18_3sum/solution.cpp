// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(1) (Trade-off)
// Explanation: Optimal: Sort the array. Use a loop to fix `i`, then use a Two-Pointer approach (`j`, `k`) for the remaining array to find sum `0 - nums[i]`.

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1, k = n - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}

