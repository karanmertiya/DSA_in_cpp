// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use two pointers, `left` at the beginning and `right` at the end of the string. Swap the characters at these pointers and move them towards each other until they meet.

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while(left < right) {
        swap(s[left++], s[right--]);
    }
}

