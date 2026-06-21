// Time Complexity: O(N)
// Space Complexity: O(26)
// Explanation: Count frequencies. If max frequency > (len + 1) / 2, it's impossible. Fill the most frequent character at even indices (0, 2, 4...). Then fill the remaining characters alternately at remaining even indices and then odd indices.

string reorganizeString(string s) {
    vector<int> counts(26, 0);
    int max_f = 0, letter = 0;
    for(char c : s) {
        counts[c - 'a']++;
        if(counts[c - 'a'] > max_f) {
            max_f = counts[c - 'a'];
            letter = c - 'a';
        }
    }
    if(max_f > (s.length() + 1) / 2) return "";
    string res = s;
    int idx = 0;
    while(counts[letter] > 0) {
        res[idx] = (char)(letter + 'a');
        idx += 2;
        counts[letter]--;
    }
    for(int i = 0; i < 26; i++) {
        while(counts[i] > 0) {
            if(idx >= res.length()) idx = 1;
            res[idx] = (char)(i + 'a');
            idx += 2;
            counts[i]--;
        }
    }
    return res;
}

