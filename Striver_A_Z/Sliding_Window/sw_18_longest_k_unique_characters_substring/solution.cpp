// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Use a sliding window `[left, right]` and a hash map to count characters. If map size > K, shrink window from `left` until map size == K. If map size == K, update max length.

int longestKSubstr(string s, int k) {
    unordered_map<char, int> m;
    int left = 0, right = 0, maxLen = -1;
    while(right < s.length()) {
        m[s[right]]++;
        if(m.size() == k) maxLen = max(maxLen, right - left + 1);
        else if(m.size() > k) {
            while(m.size() > k) {
                m[s[left]]--;
                if(m[s[left]] == 0) m.erase(s[left]);
                left++;
            }
        }
        right++;
    }
    return maxLen;
}

