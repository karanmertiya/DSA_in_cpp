// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Sort array. Iterate from end. If `arr[i] - arr[i-1] < K`, we pair them, add sum to answer, and `i -= 2`. Else, `i -= 1`. Greedy approach works because pairing larger numbers gives a larger sum.

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
    sort(arr, arr + N);
    int ans = 0;
    for(int i = N - 1; i > 0; ) {
        if(arr[i] - arr[i-1] < K) {
            ans += arr[i] + arr[i-1];
            i -= 2;
        } else {
            i--;
        }
    }
    return ans;
}

