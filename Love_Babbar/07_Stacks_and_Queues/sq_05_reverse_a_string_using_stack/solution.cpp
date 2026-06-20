// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Push all characters of the string into a stack. Then pop them out one by one. The popped characters will be in reversed order.

char* reverse(char *S, int len) {
    stack<char> st;
    for(int i = 0; i < len; i++) {
        st.push(S[i]);
    }
    for(int i = 0; i < len; i++) {
        S[i] = st.top();
        st.pop();
    }
    return S;
}

