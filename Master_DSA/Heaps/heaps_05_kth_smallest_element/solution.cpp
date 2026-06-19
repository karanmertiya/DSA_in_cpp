// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Use a Max Heap of size K. Iterate through the array. For the first K elements, insert them into the heap. For the remaining elements, if the element is smaller than the top of the heap, pop the top and insert the element. The top of the heap will be the Kth smallest element.

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for(int i = l; i <= r; i++) {
        if(pq.size() < k) pq.push(arr[i]);
        else if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

