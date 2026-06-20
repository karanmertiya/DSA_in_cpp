// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use a Prefix Sum and a Hash Set. If a prefix sum repeats, or equals 0, a 0-sum subarray exists between the identical prefix sums.

#include <vector>
#include <unordered_set>

bool hasZeroSumSubarray(std::vector<int>& arr) {
    std::unordered_set<int> prefix_sums;
    int sum = 0;
    for(int num : arr) {
        sum += num;
        if(sum == 0 || prefix_sums.find(sum) != prefix_sums.end()) {
            return true;
        }
        prefix_sums.insert(sum);
    }
    return false;
}

