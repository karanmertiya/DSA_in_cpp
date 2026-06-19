// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Store `prefix_sum` -> `index` in Hash Map. If sum repeats, calculate distance `i - hash[sum]`.

#include <vector>
#include <unordered_map>
#include <algorithm>

int maxLen(std::vector<int>& arr) {
    std::unordered_map<int, int> prefix_index;
    int max_len = 0, sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(sum == 0) {
            max_len = i + 1;
        } else if(prefix_index.find(sum) != prefix_index.end()) {
            max_len = std::max(max_len, i - prefix_index[sum]);
        } else {
            prefix_index[sum] = i; // Store only first occurrence
        }
    }
    return max_len;
}

