// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a sliding window of size `pat.length()`. Keep frequency map of `pat`. Track `count` of distinct characters to match. While moving window, decrease `count` if char frequency matches. If `count == 0`, increment answer.

int search(string pat, string txt) {
    unordered_map<char, int> m;
    for(char c : pat) m[c]++;
    int count = m.size(), ans = 0, k = pat.length();
    int i = 0, j = 0;
    while(j < txt.length()) {
        if(m.find(txt[j]) != m.end()) {
            m[txt[j]]--;
            if(m[txt[j]] == 0) count--;
        }
        if(j - i + 1 < k) j++;
        else if(j - i + 1 == k) {
            if(count == 0) ans++;
            if(m.find(txt[i]) != m.end()) {
                m[txt[i]]++;
                if(m[txt[i]] == 1) count++;
            }
            i++; j++;
        }
    }
    return ans;
}

