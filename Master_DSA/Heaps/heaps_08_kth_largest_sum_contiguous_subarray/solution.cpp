// Time Complexity: O(N^2 log K)
// Space Complexity: O(N + K)
// Explanation: Iterate through all possible subarrays and calculate their sums using a prefix sum array. Maintain a Min Heap of size K to keep track of the top K sums. At the end, the top of the Min Heap is the K-th largest sum.

int kthLargestSum(int arr[], int n, int k) {
    vector<int> sum(n + 1, 0);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i - 1];
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int x = sum[j] - sum[i - 1];
            if(pq.size() < k) pq.push(x);
            else if(x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }
    }
    return pq.top();
}

