// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Create frequency arrays for `p` and a window of size `p.length()` in `s`. Slide the window across `s`, updating the window frequencies. If the arrays match, add the window's start index to the result.

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if(p.length() > s.length()) return ans;
    vector<int> countP(26, 0), countS(26, 0);
    for(int i = 0; i < p.length(); i++) {
        countP[p[i] - 'a']++;
        countS[s[i] - 'a']++;
    }
    if(countP == countS) ans.push_back(0);
    for(int i = p.length(); i < s.length(); i++) {
        countS[s[i] - 'a']++;
        countS[s[i - p.length()] - 'a']--;
        if(countP == countS) ans.push_back(i - p.length() + 1);
    }
    return ans;
}

