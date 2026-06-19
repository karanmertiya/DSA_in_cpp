// Time Complexity: O(N * K log K) where K is max string length
// Space Complexity: O(N * K)
// Explanation: Use a hash map. The key is the sorted version of the string (or a character count string), and the value is a list of original strings that match this key.

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for(string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        m[key].push_back(s);
    }
    vector<vector<string>> ans;
    for(auto it : m) ans.push_back(it.second);
    return ans;
}

