// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use a Hash Map to count occurrences. Return the element with count 1.

#include <vector>
#include <unordered_map>

int singleNumberBrute(std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;
    for(auto it : freq) {
        if(it.second == 1) return it.first;
    }
    return -1;
}

