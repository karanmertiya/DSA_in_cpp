// Time Complexity: O(N * M)
// Space Complexity: O(min(N, M))
// Explanation: Brute Force: Iterate through the first array and check each element in the second array.

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    for(int i=0; i<nums1.size(); i++) {
        bool found = false;
        for(int j=0; j<nums2.size(); j++) {
            if(nums1[i] == nums2[j]) { found = true; break; }
        }
        if(found && find(res.begin(), res.end(), nums1[i]) == res.end()) {
            res.push_back(nums1[i]);
        }
    }
    return res;
}

// Time Complexity: O(N + M) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Optimal: Store elements of the first array in a Hash Set, then iterate over the second array to find matches.

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

