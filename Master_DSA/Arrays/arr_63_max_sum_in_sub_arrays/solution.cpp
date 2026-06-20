// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: The maximum sum of two smallest elements in any subarray will always be the maximum sum of adjacent elements. So, just iterate and find the max of `arr[i] + arr[i+1]`.

long long pairWithMaxSum(long long arr[], long long N) {
    long long maxi = 0;
    for(long long i = 0; i < N - 1; i++) {
        maxi = max(maxi, arr[i] + arr[i+1]);
    }
    return maxi;
}

