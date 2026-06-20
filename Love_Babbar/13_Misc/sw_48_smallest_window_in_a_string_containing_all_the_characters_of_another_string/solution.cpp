// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Same as Minimum Window Substring. Use frequency map of `P` and a sliding window over `S`. Shrink window from left when all characters match to find the minimum length.

string smallestWindow (string s, string p) {
    if(p.length() > s.length()) return "-1";
    unordered_map<char, int> m;
    for(char c : p) m[c]++;
    int count = m.size(), i = 0, j = 0, minLen = INT_MAX, start = 0;
    while(j < s.length()) {
        if(m.find(s[j]) != m.end()) {
            m[s[j]]--;
            if(m[s[j]] == 0) count--;
        }
        while(count == 0) {
            if(j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }
            if(m.find(s[i]) != m.end()) {
                m[s[i]]++;
                if(m[s[i]] > 0) count++;
            }
            i++;
        }
        j++;
    }
    if(minLen == INT_MAX) return "-1";
    return s.substr(start, minLen);
}

