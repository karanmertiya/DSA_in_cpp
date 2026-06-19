// Time Complexity: O(K^2 log K)
// Space Complexity: O(K)
// Explanation: Use a Min Heap to store the first element of each array along with its 2D index. Extract the minimum element, add it to the result, and insert the next element from the same array into the Min Heap.

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < K; i++) pq.push({arr[i][0], {i, 0}});
    vector<int> ans;
    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        ans.push_back(curr.first);
        int i = curr.second.first, j = curr.second.second;
        if(j + 1 < K) pq.push({arr[i][j + 1], {i, j + 1}});
    }
    return ans;
}

