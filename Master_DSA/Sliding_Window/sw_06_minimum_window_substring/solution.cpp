// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain a frequency map of `t`. Expand the window by moving `right`. When the window contains all characters of `t`, try to shrink it by moving `left` to find the minimum window. Keep track of the minimum window length and its starting index.

string minWindow(string s, string t) {
    if(s.length() < t.length()) return "";
    vector<int> count(128, 0);
    for(char c : t) count[c]++;
    int l = 0, r = 0, minLen = INT_MAX, minStart = 0, required = t.length();
    while(r < s.length()) {
        if(count[s[r]] > 0) required--;
        count[s[r]]--;
        r++;
        while(required == 0) {
            if(r - l < minLen) {
                minLen = r - l;
                minStart = l;
            }
            count[s[l]]++;
            if(count[s[l]] > 0) required++;
            l++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

