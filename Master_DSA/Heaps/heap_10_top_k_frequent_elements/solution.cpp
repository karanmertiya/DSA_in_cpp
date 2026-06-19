// Time Complexity: O(N log K)
// Space Complexity: O(N)
// Explanation: Count frequencies using a map. Use a Min-Heap of size K, storing pairs `(freq, num)`. If size > K, pop. Heap will contain the top K elements.

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mpp;
    for(int num : nums) mpp[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    for(auto it : mpp) {
        minH.push({it.second, it.first});
        if(minH.size() > k) minH.pop();
    }
    vector<int> ans;
    while(!minH.empty()) {
        ans.push_back(minH.top().second);
        minH.pop();
    }
    return ans;
}

