// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Store frequency of chars in `t`. Use `left` and `right` pointers. Expand `right`, if the character is in `t`, decrease its required count. If all characters are found, update the minimum length and start shrinking from `left`.

string minWindow(string s, string t) {
    vector<int> count(128, 0);
    for(char c : t) count[c]++;
    int required = t.length();
    int left = 0, minLen = INT_MAX, minStart = 0;
    for(int right = 0; right < s.length(); right++) {
        if(count[s[right]] > 0) required--;
        count[s[right]]--;
        while(required == 0) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            count[s[left]]++;
            if(count[s[left]] > 0) required++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

