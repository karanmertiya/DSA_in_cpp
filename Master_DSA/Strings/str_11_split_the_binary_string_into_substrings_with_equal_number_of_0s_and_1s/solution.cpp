// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterate through the string, maintain a count that increments for '0' and decrements for '1' (or vice versa). Whenever the count becomes 0, it means we have found a balanced substring, so increment the answer.

int maxSubStr(string str) {
    int count0 = 0, count1 = 0, ans = 0;
    for(char c : str) {
        if(c == '0') count0++;
        else count1++;
        if(count0 == count1) ans++;
    }
    if(count0 != count1) return -1;
    return ans;
}

