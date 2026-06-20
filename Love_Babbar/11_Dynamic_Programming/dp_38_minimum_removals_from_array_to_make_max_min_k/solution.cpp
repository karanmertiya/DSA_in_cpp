// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Sort array. We want to find the longest subarray `arr[i..j]` such that `arr[j] - arr[i] <= K`. `dp[i]` could store the max `j` for index `i`. Or use Binary Search (`upper_bound`) for each `i` to find the valid `j`, maximizing `j - i + 1`. Total removed = `N - max_length`.

int removals(vector<int>& arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        int j = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - 1;
        maxLen = max(maxLen, j - i + 1);
    }
    return n - maxLen;
}

