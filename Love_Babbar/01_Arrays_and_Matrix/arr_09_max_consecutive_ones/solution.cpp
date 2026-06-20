// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>
#include <algorithm>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max_cnt = 0, current_cnt = 0;
    for(int num : nums) {
        if(num == 1) {
            current_cnt++;
            max_cnt = std::max(max_cnt, current_cnt);
        } else {
            current_cnt = 0;
        }
    }
    return max_cnt;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Iterate while counting 1s. If a 0 is found, update max count and reset current count to 0.

#include <vector>
#include <algorithm>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int max_cnt = 0, current_cnt = 0;
    for(int num : nums) {
        if(num == 1) {
            current_cnt++;
            max_cnt = std::max(max_cnt, current_cnt);
        } else {
            current_cnt = 0;
        }
    }
    return max_cnt;
}

