// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.

#include <string>
#include <stack>
bool isValid(std::string s) {
    std::stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top == '(') || 
               (c == '}' && top == '{') || 
               (c == ']' && top == '[')) {
                st.pop();
            } else return false;
        }
    }
    return st.empty();
}

