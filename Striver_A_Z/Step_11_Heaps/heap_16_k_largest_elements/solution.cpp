// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Maintain a min-heap of size K. Iterate through the array. If the heap has < K elements, push. Else if the current element > heap's top, pop the top and push the current element. The heap will contain the K largest elements.

vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

