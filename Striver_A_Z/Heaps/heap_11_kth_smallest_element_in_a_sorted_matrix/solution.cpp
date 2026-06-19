// Time Complexity: O(K log N)
// Space Complexity: O(N)
// Explanation: Similar to merging K sorted arrays. Push the first element of each row into a min-heap. Pop the minimum element `K-1` times, pushing the next element from the popped element's row. The Kth popped element is the answer. (Binary Search is also optimal here).

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < n; i++) pq.push({matrix[i][0], i, 0});
    for(int i = 0; i < k - 1; i++) {
        auto curr = pq.top(); pq.pop();
        int r = curr[1], c = curr[2];
        if(c + 1 < n) pq.push({matrix[r][c + 1], r, c + 1});
    }
    return pq.top()[0];
}

