// Time Complexity: O(N log K) Heap, O(N) avg Quickselect
// Space Complexity: O(K) Heap, O(1) Quickselect
// Explanation: Min-heap: Keep a min-heap of size K. The root is the Kth largest. Quickselect: Partition the array like in Quicksort, recursively searching only the partition containing the target index.

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int num : nums) {
        pq.push(num);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

