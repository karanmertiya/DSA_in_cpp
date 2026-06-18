// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Use two pointers, one at the beginning and one at the end, swapping characters until they meet.

#include <vector>
#include <utility>

void reverseString(std::vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while(left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
}

