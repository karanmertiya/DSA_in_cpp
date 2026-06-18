// Time Complexity: O(N log N) (Constraint)
// Space Complexity: O(N)
// Explanation: Binary Search Patience Sorting method. Maintain a `temp` array. If current element is larger than `temp.back()`, append. Else, replace the first element >= current.

#include <vector>
#include <algorithm>
int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> temp;
    for(int num : nums) {
        auto it = std::lower_bound(temp.begin(), temp.end(), num);
        if(it == temp.end()) temp.push_back(num);
        else *it = num;
    }
    return temp.size();
}

