// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Recursively pop elements until the stack is empty. When returning from the recursive call, use another recursive function `sortedInsert` to insert the popped element into its correct sorted position in the stack.

void sortedInsert(stack<int>& s, int element) {
    if(s.empty() || element > s.top()) {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(num);
}
void sortStack(stack<int>& s) {
    if(s.empty()) return;
    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}

