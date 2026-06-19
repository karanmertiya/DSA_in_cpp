// Time Complexity: O(N log K)
// Space Complexity: O(N)
// Explanation: Count frequencies using a hash map. Maintain a min-heap of size K storing `(frequency, element)`. Push each pair into the heap. If size > K, pop. The remaining elements in the heap are the top K frequent.

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(int num : nums) count[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto it : count) {
        pq.push({it.second, it.first});
        if(pq.size() > k) pq.pop();
    }
    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

