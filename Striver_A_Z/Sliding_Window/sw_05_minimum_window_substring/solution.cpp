// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Use a map to count required characters of `t`. Expand right pointer until `required == 0`. Then shrink left pointer to find minimum valid window.

#include <string>
#include <vector>

std::string minWindow(std::string s, std::string t) {
    std::vector<int> map(256, 0);
    for(char c : t) map[c]++;
    
    int left = 0, right = 0, required = t.length();
    int min_len = 1e9, start_idx = -1;
    
    while(right < s.length()) {
        if(map[s[right]] > 0) required--;
        map[s[right]]--;
        
        while(required == 0) {
            if(right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }
            map[s[left]]++;
            if(map[s[left]] > 0) required++;
            left++;
        }
        right++;
    }
    return start_idx == -1 ? "" : s.substr(start_idx, min_len);
}

