// Time Complexity: O(N log K)
// Space Complexity: O(K)
// Explanation: Use a max-heap of size K to store `(distance_squared, index)`. For each point, if the heap size is < K, push it. Otherwise, if its distance is less than the max-heap's top distance, pop the top and push the new point.

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < points.size(); i++) {
        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        pq.push({dist, i});
        if(pq.size() > k) pq.pop();
    }
    vector<vector<int>> ans;
    while(!pq.empty()) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }
    return ans;
}

