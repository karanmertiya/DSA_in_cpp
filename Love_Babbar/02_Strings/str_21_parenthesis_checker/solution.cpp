// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a stack to keep track of opening brackets. If a closing bracket is encountered, check if it matches the top of the stack.

bool ispar(string x) {
    stack<char> s;
    for(char c : x) {
        if(c == '(' || c == '{' || c == '[') s.push(c);
        else {
            if(s.empty()) return false;
            if(c == ')' && s.top() != '(') return false;
            if(c == '}' && s.top() != '{') return false;
            if(c == ']' && s.top() != '[') return false;
            s.pop();
        }
    }
    return s.empty();
}

