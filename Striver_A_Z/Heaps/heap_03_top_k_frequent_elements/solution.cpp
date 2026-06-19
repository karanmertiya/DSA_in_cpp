// Time Complexity: O(N log K)
// Space Complexity: O(N)
// Explanation: Use a Hash Map to count frequencies. Use a Min-Heap of size `k` to keep track of the top `k` elements.

#include <vector>
#include <unordered_map>
#include <queue>
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> mpp;
    for(int num : nums) mpp[num]++;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for(auto it : mpp) {
        pq.push({it.second, it.first});
        if(pq.size() > k) pq.pop();
    }
    std::vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

