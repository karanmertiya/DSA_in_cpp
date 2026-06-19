// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: If lengths differ, return false. Create an array of size 26. Increment counts for characters in `s` and decrement for characters in `t`. If all counts are 0, it's an anagram.

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    vector<int> count(26, 0);
    for(int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if(count[i] != 0) return false;
    }
    return true;
}

