// Time Complexity: O(2^N)
// Space Complexity: O(N)
// Explanation: Keep track of the number of elements included in subset 1 and their sum. Recurse by including the current element in subset 1 or subset 2. Base case: if we reach end, check if subset 1 has `n/2` elements. If so, compute difference and update global minimum.

int minDiff;
void solve(vector<int>& arr, int ind, int cnt, int sum1, int totalSum, int n) {
    if(ind == n) {
        if(cnt == n / 2) {
            int sum2 = totalSum - sum1;
            minDiff = min(minDiff, abs(sum1 - sum2));
        }
        return;
    }
    if(cnt < n / 2) solve(arr, ind + 1, cnt + 1, sum1 + arr[ind], totalSum, n);
    solve(arr, ind + 1, cnt, sum1, totalSum, n);
}
int tugOfWar(vector<int>& arr) {
    int totalSum = 0;
    for(int x : arr) totalSum += x;
    minDiff = INT_MAX;
    solve(arr, 0, 0, 0, totalSum, arr.size());
    return minDiff;
}

