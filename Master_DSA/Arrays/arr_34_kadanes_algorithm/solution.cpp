// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain `max_sum` and `curr_sum`. For each element, `curr_sum = max(element, curr_sum + element)`. `max_sum = max(max_sum, curr_sum)`.

long long maxSubarraySum(int arr[], int n) {
    long long maxSum = arr[0], currSum = arr[0];
    for(int i = 1; i < n; i++) {
        currSum = max((long long)arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

