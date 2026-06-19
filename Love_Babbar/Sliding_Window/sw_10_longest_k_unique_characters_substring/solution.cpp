// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Maintain a hash map of character frequencies. Expand the window by moving `j`. If the number of unique characters exceeds `k`, shrink the window from the left (`i`) until the number of unique characters is `k`. Update the maximum length when exactly `k` unique characters are present.

int longestKSubstr(string s, int k) {
    unordered_map<char, int> count;
    int i = 0, j = 0, maxLen = -1;
    while(j < s.length()) {
        count[s[j]]++;
        if(count.size() == k) maxLen = max(maxLen, j - i + 1);
        else if(count.size() > k) {
            while(count.size() > k) {
                count[s[i]]--;
                if(count[s[i]] == 0) count.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return maxLen;
}

