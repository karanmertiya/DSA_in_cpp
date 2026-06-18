// Time Complexity: O(2N) (Trade-off)
// Space Complexity: O(1)
// Explanation: Maintain a window counting zeros. If zeros exceed K, shrink from left.

#include <vector>
#include <algorithm>

int longestOnesBetter(std::vector<int>& nums, int k) {
    int left = 0, zeros = 0, max_len = 0;
    for(int right = 0; right < nums.size(); right++) {
        if(nums[right] == 0) zeros++;
        while(zeros > k) {
            if(nums[left] == 0) zeros--;
            left++;
        }
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Optimal: Never shrink the window, only slide it when invalid. This retains the `max_len` automatically.

#include <vector>

int longestOnesOptimal(std::vector<int>& nums, int k) {
    int left = 0, zeros = 0;
    for(int right = 0; right < nums.size(); right++) {
        if(nums[right] == 0) zeros++;
        if(zeros > k) {
            if(nums[left] == 0) zeros--;
            left++;
        }
    }
    return nums.size() - left;
}

