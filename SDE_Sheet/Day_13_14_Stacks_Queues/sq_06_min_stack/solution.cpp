// Time Complexity: O(1) per operation
// Space Complexity: O(N)
// Explanation: Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.

class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {}
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};

