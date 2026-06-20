// Time Complexity: O(N log M)
// Space Complexity: O(1)
// Explanation: Optimal: Since rows are sorted, use binary search (`lower_bound` of 1) to find the first index of 1 in each row. The number of 1s is `m - index`. Keep track of the row with the maximum 1s.

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
    int max_cnt = 0, index = -1;
    for(int i = 0; i < n; i++) {
        int cnt_ones = m - lowerBound(arr[i], m, 1);
        if(cnt_ones > max_cnt) {
            max_cnt = cnt_ones;
            index = i;
        }
    }
    return index;
}

