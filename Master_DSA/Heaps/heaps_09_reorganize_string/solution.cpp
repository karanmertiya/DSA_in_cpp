// Time Complexity: O(N log 26)
// Space Complexity: O(26)
// Explanation: Count character frequencies. Use a Max Heap storing `(freq, char)`. Pop the top element, add it to the result, decrement its frequency, and temporarily store it (so it can't be picked in the next iteration). If the stored element has `freq > 0`, push it back. If the heap is empty but the stored element is not, it's impossible.

string reorganizeString(string s) {
    unordered_map<char, int> count;
    for(char c : s) count[c]++;
    priority_queue<pair<int, char>> pq;
    for(auto it : count) pq.push({it.second, it.first});
    string res = "";
    pair<int, char> prev = {-1, '#'};
    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        res += curr.second;
        curr.first--;
        if(prev.first > 0) pq.push(prev);
        prev = curr;
    }
    return res.length() == s.length() ? res : "";
}

