// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N)
// Explanation: Use a Stack. Push opening brackets. For closing brackets, pop the stack and check if it matches the corresponding opening bracket.

#include <string>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) return false;
            st.pop();
        }
    }
    return st.empty();
}

