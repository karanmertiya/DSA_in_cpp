// Time Complexity: O(N log N) (Trade-off)
// Space Complexity: O(1) or O(N) (Language dependent)
// Explanation: Sort both strings and compare if they are identical.

#include <string>
#include <algorithm>

bool isAnagramBrute(std::string s, std::string t) {
    if(s.length() != t.length()) return false;
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Use a fixed size frequency array (Hash Map) to count character occurrences.

#include <string>
#include <vector>

bool isAnagramOptimal(std::string s, std::string t) {
    if(s.length() != t.length()) return false;
    std::vector<int> count(26, 0);
    for(int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for(int c : count) {
        if(c != 0) return false;
    }
    return true;
}

