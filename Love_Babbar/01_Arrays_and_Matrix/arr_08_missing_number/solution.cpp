// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Brute Force: Linear search for each number from 0 to N inside the array.

int missingNumber(vector<int>& nums) {
    for(int i=0; i<=nums.size(); i++) {
        bool found = false;
        for(int x : nums) {
            if(x == i) found = true;
        }
        if(!found) return i;
    }
    return -1;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Using XOR: XORing a number with itself results in 0. XOR all indices `[0,n]` and all elements in `nums`. The missing number will remain.

#include <vector>

int missingNumber(std::vector<int>& nums) {
    int res = nums.size();
    for(int i = 0; i < nums.size(); i++) {
        res ^= i ^ nums[i];
    }
    return res;
}

