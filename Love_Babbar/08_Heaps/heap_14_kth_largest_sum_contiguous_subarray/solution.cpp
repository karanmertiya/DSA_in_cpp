// Time Complexity: O(N^2 log K)
// Space Complexity: O(K)
// Explanation: Iterate all subarrays using two nested loops. Maintain a min-heap of size K to store the top K sums. If the heap size < K, push the current sum. If the heap size == K and current sum > heap top, pop and push current sum. The top of the heap is the Kth largest sum.

int kthLargest(vector<int> &Arr, int N, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = i; j < N; j++) {
            sum += Arr[j];
            if(pq.size() < K) pq.push(sum);
            else if(sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}

