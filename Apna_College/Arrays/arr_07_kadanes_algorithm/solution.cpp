// Time Complexity: O(N<sup>2</sup>) (Trade-off)
// Space Complexity: O(1)
// Explanation: Check all possible subarrays and calculate their sum.

#include <vector>
#include <algorithm>
#include <climits>

int maxSubArrayBrute(std::vector<int>& nums) {
    int maxi = INT_MIN;
    for(int i=0; i<nums.size(); i++) {
        int sum = 0;
        for(int j=i; j<nums.size(); j++) {
            sum += nums[j];
            maxi = std::max(maxi, sum);
        }
    }
    return maxi;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Kadane's: Maintain `curr_sum`. If `curr_sum` drops below zero, reset it. Track maximum.

#include <vector>
#include <algorithm>
#include <climits>

int maxSubArrayOptimal(std::vector<int>& nums) {
    int maxi = INT_MIN;
    int sum = 0;
    for(int num : nums) {
        sum += num;
        maxi = std::max(maxi, sum);
        if (sum < 0) sum = 0; // Reset condition
    }
    return maxi;
}

