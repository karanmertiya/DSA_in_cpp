// Time Complexity: O(N log A)
// Space Complexity: O(A)
// Explanation: Count character frequencies. Use a max-heap to store (count, char). Pop the top two most frequent characters, append them to the result, decrement their counts, and push them back if count > 0. If one character is left and its count > 1, it's impossible.

string reorganizeString(string s) {
    unordered_map<char, int> count;
    for(char c : s) count[c]++;
    priority_queue<pair<int, char>> pq;
    for(auto it : count) pq.push({it.second, it.first});
    string res = "";
    while(pq.size() > 1) {
        auto top1 = pq.top(); pq.pop();
        auto top2 = pq.top(); pq.pop();
        res += top1.second;
        res += top2.second;
        if(--top1.first > 0) pq.push(top1);
        if(--top2.first > 0) pq.push(top2);
    }
    if(!pq.empty()) {
        if(pq.top().first > 1) return "";
        res += pq.top().second;
    }
    return res;
}

