// Time Complexity: O(N * M)
// Space Complexity: O(1) excluding output
// Explanation: Build a Trie with the queries (optional, can also be done linearly). Better approach: for each query, match characters with pattern. If characters match, increment pattern index. If characters mismatch and query character is uppercase, it's a mismatch. Finally, check if pattern index reached pattern length.

vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans;
    for(string q : queries) {
        int i = 0;
        bool match = true;
        for(char c : q) {
            if(i < pattern.length() && c == pattern[i]) i++;
            else if(isupper(c)) {
                match = false;
                break;
            }
        }
        if(i < pattern.length()) match = false;
        ans.push_back(match);
    }
    return ans;
}

