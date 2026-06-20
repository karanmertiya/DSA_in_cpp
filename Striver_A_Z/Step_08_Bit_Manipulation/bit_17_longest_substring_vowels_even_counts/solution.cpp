// Time Complexity: O(N)
// Space Complexity: O(32) since only 5 bits used
// Explanation: Use a 5-bit mask to represent the parity of counts for 'a','e','i','o','u'. If we encounter a vowel, flip its bit. If the same mask is seen again at index `i` (was previously seen at `j`), then the substring `s[j+1...i]` has even vowel counts. Use a hash map to store first occurrence of each mask.

int findTheLongestSubstring(string s) {
    unordered_map<int, int> m;
    m[0] = -1;
    int mask = 0, maxLen = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'a') mask ^= (1 << 0);
        else if(s[i] == 'e') mask ^= (1 << 1);
        else if(s[i] == 'i') mask ^= (1 << 2);
        else if(s[i] == 'o') mask ^= (1 << 3);
        else if(s[i] == 'u') mask ^= (1 << 4);
        if(m.count(mask)) {
            maxLen = max(maxLen, i - m[mask]);
        } else {
            m[mask] = i;
        }
    }
    return maxLen;
}

