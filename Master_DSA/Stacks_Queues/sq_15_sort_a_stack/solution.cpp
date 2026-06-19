// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Recursively pop elements until the stack is empty. Then, as the recursion unwinds, use another recursive function `sortedInsert` to insert the element in its sorted position.

void sortedInsert(stack<int>& s, int x) {
    if(s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}
void SortedStack::sort() {
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    sort();
    sortedInsert(s, temp);
}

