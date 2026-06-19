// Time Complexity: O(N log N + N * L^2) where L is max word length
// Space Complexity: O(N * L)
// Explanation: Sort words by length. Use a hash map `dp` to store the longest chain ending at `word`. For each word, try removing one character at a time to form `prev_word`. `dp[word] = max(dp[word], dp[prev_word] + 1)`.

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    unordered_map<string, int> dp;
    int max_len = 1;
    for(const string& word : words) {
        dp[word] = 1;
        for(int i = 0; i < word.length(); i++) {
            string prev = word.substr(0, i) + word.substr(i + 1);
            if(dp.find(prev) != dp.end()) {
                dp[word] = max(dp[word], dp[prev] + 1);
            }
        }
        max_len = max(max_len, dp[word]);
    }
    return max_len;
}

