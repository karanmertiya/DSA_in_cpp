// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;
    vector<pair<int, char>> v;
    for(auto it : freq) v.push_back({it.second, it.first});
    sort(v.rbegin(), v.rend());
    string ans = "";
    for(auto it : v) {
        ans += string(it.first, it.second);
    }
    return ans;
}

// Time Complexity: O(N log K) where K is unique chars
// Space Complexity: O(K)
// Explanation: Optimal: Count frequencies using a hash map. Add pairs `(freq, char)` to a max heap or vector and sort. Reconstruct string.

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;
    vector<pair<int, char>> v;
    for(auto it : freq) v.push_back({it.second, it.first});
    sort(v.rbegin(), v.rend());
    string ans = "";
    for(auto it : v) {
        ans += string(it.first, it.second);
    }
    return ans;
}

