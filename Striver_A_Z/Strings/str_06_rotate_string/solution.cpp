// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: If s and goal have the same length, check if `goal` is a substring of `s + s`.

#include <string>

bool rotateString(std::string s, std::string goal) {
    if(s.length() != goal.length()) return false;
    std::string combined = s + s;
    return combined.find(goal) != std::string::npos;
}

