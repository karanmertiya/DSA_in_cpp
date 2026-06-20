// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Optimal: Sort the array. Find the minimum difference between `A[i+M-1]` and `A[i]` for all possible `i` from `0` to `N-M`.

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    long long min_diff = LLONG_MAX;
    for(int i = 0; i + m - 1 < n; i++) {
        if(a[i + m - 1] - a[i] < min_diff) {
            min_diff = a[i + m - 1] - a[i];
        }
    }
    return min_diff;
}

