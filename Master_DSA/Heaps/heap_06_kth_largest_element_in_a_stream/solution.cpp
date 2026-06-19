// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Maintain a min-heap of size K. For each element in the stream, push it to the heap. If the heap size exceeds K, pop the top (minimum) element. The top of the heap is the Kth largest element. If the size is less than K, return -1.

vector<int> kthLargest(int k, int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
        if(pq.size() < k) res.push_back(-1);
        else res.push_back(pq.top());
    }
    return res;
}

