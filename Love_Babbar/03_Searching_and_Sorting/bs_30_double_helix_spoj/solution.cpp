// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Optimal: Use two pointers to traverse both sorted arrays simultaneously. Accumulate sums `sum1` and `sum2`. When elements match (intersection), add `max(sum1, sum2) + element` to the total answer and reset `sum1` and `sum2`. After the loop, add the remaining max sum.

long long maxPathSum(vector<int>& arr1, vector<int>& arr2) {
    long long sum1 = 0, sum2 = 0, ans = 0;
    int i = 0, j = 0, n = arr1.size(), m = arr2.size();
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) sum1 += arr1[i++];
        else if(arr1[i] > arr2[j]) sum2 += arr2[j++];
        else {
            ans += max(sum1, sum2) + arr1[i];
            sum1 = 0; sum2 = 0;
            i++; j++;
        }
    }
    while(i < n) sum1 += arr1[i++];
    while(j < m) sum2 += arr2[j++];
    ans += max(sum1, sum2);
    return ans;
}

