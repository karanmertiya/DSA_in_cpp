// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Variation of LIS. Create an array `msis` initialized with the given array values. For each `i` from 1 to `n-1`, for each `j` from 0 to `i-1`, if `arr[i] > arr[j]` and `msis[i] < msis[j] + arr[i]`, update `msis[i]`. The max in `msis` is the answer.

int maxSumIS(int arr[], int n) {
    vector<int> msis(arr, arr + n);
    int max_sum = msis[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i];
            }
        }
        max_sum = max(max_sum, msis[i]);
    }
    return max_sum;
}

