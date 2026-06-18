// Time Complexity: O(2N) &cong; O(N) (Trade-off)
// Space Complexity: O(1)
// Explanation: Count 0s, 1s, and 2s, then overwrite the array linearly.

#include <vector>

void sortColorsBetter(std::vector<int>& nums) {
    int c0 = 0, c1 = 0, c2 = 0;
    for(int num : nums) {
        if(num == 0) c0++;
        else if(num == 1) c1++;
        else c2++;
    }
    for(int i = 0; i < c0; i++) nums[i] = 0;
    for(int i = c0; i < c0+c1; i++) nums[i] = 1;
    for(int i = c0+c1; i < nums.size(); i++) nums[i] = 2;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Dutch National Flag Algorithm: 3 Pointers (low, mid, high) sorting in a single pass.

#include <vector>
#include <utility>

void sortColorsOptimal(std::vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid <= high) {
        if(nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++; mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

