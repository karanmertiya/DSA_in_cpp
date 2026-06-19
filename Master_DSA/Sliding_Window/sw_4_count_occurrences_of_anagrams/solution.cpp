// Time Complexity: O(N)
// Space Complexity: O(26) = O(1)
// Explanation: Maintain a frequency map of the pattern. Use a sliding window of size equal to the length of the pattern. Keep track of the number of characters fully matched (`count`). If `count` equals the number of unique characters in the pattern, an anagram is found.

int search(string pat, string txt) {
    int k = pat.length(), n = txt.length();
    if(k > n) return 0;
    vector<int> count(26, 0);
    for(char c : pat) count[c - 'a']++;
    int i = 0, j = 0, ans = 0;
    int distinct = 0;
    for(int x : count) if(x > 0) distinct++;
    while(j < n) {
        count[txt[j] - 'a']--;
        if(count[txt[j] - 'a'] == 0) distinct--;
        if(j - i + 1 < k) j++;
        else if(j - i + 1 == k) {
            if(distinct == 0) ans++;
            count[txt[i] - 'a']++;
            if(count[txt[i] - 'a'] == 1) distinct++;
            i++; j++;
        }
    }
    return ans;
}

