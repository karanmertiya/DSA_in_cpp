// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a frequency array of size 26. Increment for `s`, decrement for `t`. Check if all counts are 0.

#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) {
    if(s.length() != t.length()) return false;
    std::vector<int> freq(26, 0);
    for(int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for(int count : freq) {
        if(count != 0) return false;
    }
    return true;
}

