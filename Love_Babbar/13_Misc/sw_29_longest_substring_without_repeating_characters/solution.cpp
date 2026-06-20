// Time Complexity: O(N)
// Space Complexity: O(min(N, M))
// Explanation: Sliding window with a Hash Map storing the latest index of each character. Move `left` pointer to `max(left, map[char] + 1)`.

#include <string>
#include <vector>
#include <algorithm>
int lengthOfLongestSubstring(std::string s) {
    std::vector<int> mpp(256, -1);
    int left = 0, right = 0, max_len = 0;
    while(right < s.length()) {
        if(mpp[s[right]] != -1) {
            left = std::max(left, mpp[s[right]] + 1);
        }
        mpp[s[right]] = right;
        max_len = std::max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

