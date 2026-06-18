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

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: XOR all elements. Identical pairs cancel out (A ^ A = 0), leaving only the unique element (0 ^ B = B).

#include <vector>

int singleNumberOptimal(std::vector<int>& nums) {
    int xor_res = 0;
    for(int num : nums) {
        xor_res ^= num;
    }
    return xor_res;
}

