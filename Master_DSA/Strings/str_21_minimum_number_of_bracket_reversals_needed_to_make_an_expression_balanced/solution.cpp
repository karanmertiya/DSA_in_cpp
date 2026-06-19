// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: If the length of string is odd, return -1. Remove all balanced parts. The remaining string looks like `}}}{{{`. The number of reversals needed is `ceil(close/2) + ceil(open/2)`.

int countRev(string s) {
    if(s.length() % 2 != 0) return -1;
    stack<char> st;
    for(char c : s) {
        if(c == '{') st.push(c);
        else {
            if(!st.empty() && st.top() == '{') st.pop();
            else st.push(c);
        }
    }
    int open = 0, close = 0;
    while(!st.empty()) {
        if(st.top() == '{') open++;
        else close++;
        st.pop();
    }
    return ceil(open / 2.0) + ceil(close / 2.0);
}

