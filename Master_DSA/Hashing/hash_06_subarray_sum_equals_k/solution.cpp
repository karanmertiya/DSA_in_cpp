// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Explanation: Brute Force: Generate all possible subarrays and compute their sums.

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    for(int i=0; i<nums.size(); i++) {
        int sum = 0;
        for(int j=i; j<nums.size(); j++) {
            sum += nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Optimal: Maintain a Hash Map of `prefix_sum` -> `frequency`. If `curr_sum - k` exists in the map, add its frequency to the count.

#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefix_freq;
    prefix_freq[0] = 1; // Base case for subarrays starting at index 0
    
    int count = 0, sum = 0;
    for(int num : nums) {
        sum += num;
        int remove = sum - k;
        if(prefix_freq.find(remove) != prefix_freq.end()) {
            count += prefix_freq[remove];
        }
        prefix_freq[sum]++;
    }
    return count;
}

