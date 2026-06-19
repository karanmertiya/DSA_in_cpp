// Time Complexity: O(N log 26)
// Space Complexity: O(26)
// Explanation: Hash map to store frequencies, then max-heap to process them in descending order of frequency.

string frequencySort(string s) {
    unordered_map<char, int> mpp;
    for(char c : s) mpp[c]++;
    priority_queue<pair<int, char>> pq;
    for(auto it : mpp) pq.push({it.second, it.first});
    string ans = "";
    while(!pq.empty()) {
        ans += string(pq.top().first, pq.top().second);
        pq.pop();
    }
    return ans;
}

