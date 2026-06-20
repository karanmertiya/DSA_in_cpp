// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Optimal: Prefix Sum Map storing indices. Check if `sum - K` exists in map and calculate index difference.

#include <vector>
#include <unordered_map>
#include <algorithm>

int lenOfLongSubarr(std::vector<int>& arr, int k) {
    std::unordered_map<long long, int> prefix_index;
    int max_len = 0;
    long long sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == k) {
            max_len = i + 1;
        }
        long long needed = sum - k;
        if(prefix_index.find(needed) != prefix_index.end()) {
            max_len = std::max(max_len, i - prefix_index[needed]);
        }
        if(prefix_index.find(sum) == prefix_index.end()) {
            prefix_index[sum] = i;
        }
    }
    return max_len;
}

