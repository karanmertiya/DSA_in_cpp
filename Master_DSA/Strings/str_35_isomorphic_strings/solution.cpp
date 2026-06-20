// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use two arrays to map characters from `s` to `t` and `t` to `s`. If `s[i]` is mapped to a character other than `t[i]`, or `t[i]` is mapped to a character other than `s[i]`, return false. Else, create the mappings.

bool isIsomorphic(string s, string t) {
    vector<int> m1(256, -1), m2(256, -1);
    for(int i = 0; i < s.length(); i++) {
        if(m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i;
        m2[t[i]] = i;
    }
    return true;
}

