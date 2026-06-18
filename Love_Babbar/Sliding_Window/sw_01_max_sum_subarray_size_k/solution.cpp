// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Fixed Sliding Window: Maintain a window of size K. Slide it by adding the next element and subtracting the first element of the previous window.

#include <vector>
#include <algorithm>

long long maximumSumSubarray(int K, std::vector<int>& arr) {
    long long max_sum = 0, current_sum = 0;
    for(int i=0; i<K; i++) current_sum += arr[i];
    max_sum = current_sum;
    
    for(int i=K; i<arr.size(); i++) {
        current_sum += arr[i] - arr[i-K];
        max_sum = std::max(max_sum, current_sum);
    }
    return max_sum;
}

