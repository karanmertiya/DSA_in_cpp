// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Count frequencies using a map. Then, sort the map entries by frequency in descending order, or use a Max Heap, or use Bucket Sort (where index is frequency and value is a list of characters). Build the new string by appending each character `freq` times.

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

