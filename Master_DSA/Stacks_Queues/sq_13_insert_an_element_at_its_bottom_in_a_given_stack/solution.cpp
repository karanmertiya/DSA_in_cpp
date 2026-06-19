// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use recursion. If the stack is empty, push the element. Otherwise, pop the top element, recursively call the function, and then push the popped element back.

stack<int> insertAtBottom(stack<int> St, int X) {
    if(St.empty()) {
        St.push(X);
        return St;
    }
    int top = St.top();
    St.pop();
    St = insertAtBottom(St, X);
    St.push(top);
    return St;
}

