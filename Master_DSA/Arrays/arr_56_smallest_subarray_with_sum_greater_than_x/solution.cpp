// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Use a sliding window. Add elements to `curr_sum` and increment `end`. When `curr_sum > x`, update `min_len` and subtract `arr[start]`, increment `start`.

int smallestSubWithSum(int arr[], int n, int x) {
    int curr_sum = 0, min_len = n + 1;
    int start = 0, end = 0;
    while(end < n) {
        while(curr_sum <= x && end < n) curr_sum += arr[end++];
        while(curr_sum > x && start < n) {
            min_len = min(min_len, end - start);
            curr_sum -= arr[start++];
        }
    }
    return (min_len == n + 1) ? 0 : min_len;
}

