// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterate through the string. Maintain a `current_depth` counter. If we see `(`, increment the counter and update `max_depth`. If we see `)`, decrement the counter. Ignore other characters.

int maxDepth(string s) {
    int maxD = 0, curD = 0;
    for(char c : s) {
        if(c == '(') {
            curD++;
            maxD = max(maxD, curD);
        } else if(c == ')') {
            curD--;
        }
    }
    return maxD;
}

