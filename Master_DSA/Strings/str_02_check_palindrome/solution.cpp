// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Clean the string to remove non-alphanumeric characters, convert to lowercase, and check if it equals its reverse.

#include <string>
#include <cctype>
#include <algorithm>

bool isPalindromeBrute(std::string s) {
    std::string clean = "";
    for(char c : s) {
        if(std::isalnum(c)) clean += std::tolower(c);
    }
    std::string rev = clean;
    std::reverse(rev.begin(), rev.end());
    return clean == rev;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Two-pointer approach skipping non-alphanumeric characters in a single pass without extra memory.

#include <string>
#include <cctype>

bool isPalindromeOptimal(std::string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        while(left < right && !std::isalnum(s[left])) left++;
        while(left < right && !std::isalnum(s[right])) right--;
        if(std::tolower(s[left]) != std::tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

