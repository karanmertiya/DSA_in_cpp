// Time Complexity: O(N log M) where M is unique characters
// Space Complexity: O(M)
// Explanation: Count frequencies of each character. Store pairs of `(frequency, character)` in a max-heap (or sort an array). Construct the result string by popping from the heap.

string frequencySort(string s) {
    unordered_map<char, int> counts;
    for(char c : s) counts[c]++;
    priority_queue<pair<int, char>> pq;
    for(auto& p : counts) pq.push({p.second, p.first});
    string res = "";
    while(!pq.empty()) {
        res += string(pq.top().first, pq.top().second);
        pq.pop();
    }
    return res;
}

