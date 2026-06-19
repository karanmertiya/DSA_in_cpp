// Time Complexity: O(N log K) Heap, O(N) Bucket Sort
// Space Complexity: O(N)
// Explanation: Count frequencies using a hash map. Use a min-heap of size `k` storing pairs of `(frequency, element)`. Or use bucket sort where index is frequency and value is list of elements with that frequency.

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for(int num : nums) counts[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto& p : counts) {
        pq.push({p.second, p.first});
        if(pq.size() > k) pq.pop();
    }
    vector<int> res;
    while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

