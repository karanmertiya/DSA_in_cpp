// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Brute Force: Use two nested loops to count occurrences of each element.

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(nums[j] == nums[i]) cnt++;
        }
        if(cnt > n/2) return nums[i];
    }
    return -1;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Optimal: Moore's Voting Algorithm. Track a candidate and a counter. Increment if same as candidate, decrement if different. If zero, pick new candidate.

#include <vector>

int majorityElement(std::vector<int>& nums) {
    int count = 0, candidate = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        if (num == candidate) count++;
        else count--;
    }
    return candidate;
}

