// Time Complexity: O(K log N) or O(N log(max-min))
// Space Complexity: O(N) or O(1)
// Explanation: Min-heap: Push the first element of each row. Pop `K-1` times, pushing the next element in the row of the popped element. The `K`th popped element is the answer. Binary search: search space `matrix[0][0]` to `matrix[n-1][n-1]`. Count elements <= `mid` using two pointers.

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < min(n, k); i++) pq.push({matrix[i][0], i, 0});
    while(k-- > 1) {
        auto curr = pq.top(); pq.pop();
        int r = curr[1], c = curr[2];
        if(c + 1 < n) pq.push({matrix[r][c+1], r, c+1});
    }
    return pq.top()[0];
}

