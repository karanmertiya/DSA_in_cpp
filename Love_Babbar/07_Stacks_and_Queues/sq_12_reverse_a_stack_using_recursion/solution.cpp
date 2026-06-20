// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Recursively pop all elements until the stack is empty. Then, as the recursion unwinds, use another recursive function `insertAtBottom` to push the elements at the bottom.

void insertAtBottom(stack<int>& St, int X) {
    if(St.empty()) {
        St.push(X);
        return;
    }
    int top = St.top();
    St.pop();
    insertAtBottom(St, X);
    St.push(top);
}
void Reverse(stack<int> &St) {
    if(St.empty()) return;
    int top = St.top();
    St.pop();
    Reverse(St);
    insertAtBottom(St, top);
}

