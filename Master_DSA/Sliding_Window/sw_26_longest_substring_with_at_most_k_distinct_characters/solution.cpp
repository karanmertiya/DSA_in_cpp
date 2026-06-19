// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Sliding window with hash map to count characters. While map size > k, shrink window from left.

int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> m;
    int left = 0, right = 0, maxLen = 0;
    while(right < s.length()) {
        m[s[right]]++;
        while(m.size() > k) {
            m[s[left]]--;
            if(m[s[left]] == 0) m.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

