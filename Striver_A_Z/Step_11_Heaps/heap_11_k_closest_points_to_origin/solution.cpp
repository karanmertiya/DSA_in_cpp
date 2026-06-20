// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Use a max-heap of size `k` to store pairs of `(distance, point_index)`. Iterate over all points, push into heap. If heap size exceeds `k`, pop the max element. The heap will eventually hold the `k` points with minimum distance.

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < points.size(); i++) {
        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        pq.push({dist, i});
        if(pq.size() > k) pq.pop();
    }
    vector<vector<int>> res;
    while(!pq.empty()) {
        res.push_back(points[pq.top().second]);
        pq.pop();
    }
    return res;
}

