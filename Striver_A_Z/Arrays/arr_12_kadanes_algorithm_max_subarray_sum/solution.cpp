// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Kadane's Algorithm. Keep a running sum. If sum becomes negative, reset it to 0 (a negative prefix will never help a future subarray).

#include <vector>
#include <algorithm>
#include <limits.h>

int maxSubArray(std::vector<int>& nums) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for(int num : nums) {
        current_sum += num;
        max_sum = std::max(max_sum, current_sum);
        if(current_sum < 0) current_sum = 0;
    }
    return max_sum;
}

