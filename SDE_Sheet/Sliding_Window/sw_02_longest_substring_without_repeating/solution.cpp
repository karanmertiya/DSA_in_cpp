// Time Complexity: O(2N) &cong; O(N) (Trade-off)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use a Hash Set to track characters in the current window. If a duplicate is found, shrink the window from the left.

#include <string>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstringBetter(std::string s) {
    std::unordered_set<char> charSet;
    int left = 0, max_len = 0;
    for(int right = 0; right < s.length(); right++) {
        while(charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Store the latest index of each character in a Hash Map. Jump `left` directly to `map[char] + 1`.

#include <string>
#include <vector>
#include <algorithm>

int lengthOfLongestSubstringOptimal(std::string s) {
    std::vector<int> charIndex(256, -1);
    int left = 0, max_len = 0;
    for(int right = 0; right < s.length(); right++) {
        if(charIndex[s[right]] != -1) {
            left = std::max(left, charIndex[s[right]] + 1);
        }
        charIndex[s[right]] = right;
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}

