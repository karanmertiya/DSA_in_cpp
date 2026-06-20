// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Maintain a min-heap of size K. While processing the stream, if heap size is < K, push current element. If heap size == K and current element is > heap top, pop and push current element. Append heap top to result if size is K, else append -1.

vector<int> kthLargest(int k, int arr[], int n) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        if(pq.size() < k) pq.push(arr[i]);
        else if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
        if(pq.size() < k) res.push_back(-1);
        else res.push_back(pq.top());
    }
    return res;
}

