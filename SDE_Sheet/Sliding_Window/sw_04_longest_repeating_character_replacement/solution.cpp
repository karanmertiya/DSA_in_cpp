// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Sliding window tracking the `max_frequency_count` inside the window. If `window_len - max_freq > k`, slide the window.

#include <string>
#include <vector>
#include <algorithm>

int characterReplacement(std::string s, int k) {
    std::vector<int> count(26, 0);
    int left = 0, max_freq = 0;
    for(int right = 0; right < s.length(); right++) {
        max_freq = std::max(max_freq, ++count[s[right] - 'A']);
        int window_len = right - left + 1;
        if(window_len - max_freq > k) {
            count[s[left] - 'A']--;
            left++;
        }
    }
    return s.length() - left;
}

