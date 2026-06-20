// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterate through the string. Track the last seen indices of 'a', 'b', and 'c'. If all three have been seen, the number of valid substrings ending at the current index `i` is `1 + min(last_a, last_b, last_c)`. Add this to the total count.

int numberOfSubstrings(string s) {
    int last[3] = {-1, -1, -1};
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        last[s[i] - 'a'] = i;
        if(last[0] != -1 && last[1] != -1 && last[2] != -1) {
            count += (1 + min({last[0], last[1], last[2]}));
        }
    }
    return count;
}

