// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Two-pointer approach skipping non-alphanumeric characters. Compare characters from both ends.

#include <string>
#include <cctype>

bool isPalindrome(std::string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !std::isalnum(s[left])) left++;
        while (left < right && !std::isalnum(s[right])) right--;
        if (std::tolower(s[left]) != std::tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

