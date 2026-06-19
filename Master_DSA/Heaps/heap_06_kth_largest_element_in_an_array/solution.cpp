// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Use a Min-Heap of size K. Push elements into the heap. If heap size exceeds K, pop the minimum element. The top of the heap at the end is the Kth largest element.

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minH;
    for(int num : nums) {
        minH.push(num);
        if(minH.size() > k) minH.pop();
    }
    return minH.top();
}

