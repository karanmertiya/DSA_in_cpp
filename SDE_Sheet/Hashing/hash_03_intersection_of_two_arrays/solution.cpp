// Time Complexity: O(N + M) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Store elements of the first array in a Hash Set, then iterate over the second array to find matches.

#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> s(nums1.begin(), nums1.end());
    std::vector<int> res;
    for(int num : nums2) {
        if(s.find(num) != s.end()) {
            res.push_back(num);
            s.erase(num); // Ensure uniqueness
        }
    }
    return res;
}

