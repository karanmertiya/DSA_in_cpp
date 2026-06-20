// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Brute Force: Sort the array first, then count consecutive elements linearly.

int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int longest = 1, current = 1;
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] == nums[i-1]) continue;
        if(nums[i] == nums[i-1] + 1) current++;
        else {
            longest = max(longest, current);
            current = 1;
        }
    }
    return max(longest, current);
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N)
// Explanation: Optimal: Insert all elements into a Hash Set. Iterate through elements. If `num - 1` is NOT in the set, it's the start of a sequence. Count forwards.

#include <vector>
#include <unordered_set>
#include <algorithm>
int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> st(nums.begin(), nums.end());
    int max_len = 0;
    for(int num : st) {
        if(st.find(num - 1) == st.end()) {
            int curr_num = num;
            int curr_len = 1;
            while(st.find(curr_num + 1) != st.end()) {
                curr_num++;
                curr_len++;
            }
            max_len = std::max(max_len, curr_len);
        }
    }
    return max_len;
}

