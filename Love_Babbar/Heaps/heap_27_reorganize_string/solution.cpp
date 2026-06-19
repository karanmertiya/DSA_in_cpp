// Time Complexity: O(N log(26))
// Space Complexity: O(26)
// Explanation: Count character frequencies. Push pairs `(freq, char)` to a max-heap. Pop two most frequent distinct characters, append to result, decrement frequencies, and push back if frequency > 0. If at the end one character remains with freq > 1, return empty string.

string reorganizeString(string s) {
    unordered_map<char, int> count;
    for(char c : s) count[c]++;
    priority_queue<pair<int, char>> pq;
    for(auto& pair : count) pq.push({pair.second, pair.first});
    string res = "";
    while(pq.size() >= 2) {
        auto [freq1, char1] = pq.top(); pq.pop();
        auto [freq2, char2] = pq.top(); pq.pop();
        res += char1; res += char2;
        if(--freq1 > 0) pq.push({freq1, char1});
        if(--freq2 > 0) pq.push({freq2, char2});
    }
    if(!pq.empty()) {
        auto [freq, char_] = pq.top();
        if(freq > 1) return "";
        res += char_;
    }
    return res;
}

