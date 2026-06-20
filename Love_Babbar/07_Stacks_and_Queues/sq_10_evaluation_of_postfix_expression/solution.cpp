// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Iterate through the string. If it's a number, push it to stack. If it's an operator, pop two numbers from stack, apply the operator, and push the result back to stack.

int evaluatePostfix(string S) {
    stack<int> st;
    for(char c : S) {
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            if(c == '+') st.push(op1 + op2);
            else if(c == '-') st.push(op1 - op2);
            else if(c == '*') st.push(op1 * op2);
            else if(c == '/') st.push(op1 / op2);
        }
    }
    return st.top();
}

