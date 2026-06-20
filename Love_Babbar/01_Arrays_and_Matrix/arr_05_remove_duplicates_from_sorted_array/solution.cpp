// Time Complexity: O(N log N) or O(N)
// Space Complexity: O(N)
// Explanation: Brute Force: Use a HashSet to store unique elements, then put them back into the array.

int removeDuplicates(vector<int>& nums) {
    set<int> s;
    for(int x : nums) s.insert(x);
    int i = 0;
    for(int x : s) nums[i++] = x;
    return s.size();
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Two-pointer approach. Pointer `i` keeps track of unique elements, pointer `j` scans the array to find new unique elements.

#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

