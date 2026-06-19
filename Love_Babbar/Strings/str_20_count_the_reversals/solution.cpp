// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Remove all balanced brackets using a stack. The remaining string will be of the form `}}...{{...`. The required reversals will be `ceil(open_count/2) + ceil(close_count/2)`.

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

