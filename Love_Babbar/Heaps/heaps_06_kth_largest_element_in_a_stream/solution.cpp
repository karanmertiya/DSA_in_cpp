// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Maintain a Min Heap of size K. As elements arrive, add them to the heap if the heap has less than K elements. If the heap has K elements and the new element is greater than the top, pop the top and insert the new element. Print the top if heap size is K, else -1.

vector<int> kthLargest(int k, int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(pq.size() < k) pq.push(arr[i]);
        else if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
        if(pq.size() < k) ans.push_back(-1);
        else ans.push_back(pq.top());
    }
    return ans;
}

