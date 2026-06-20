// Time Complexity: O(1) amortized
// Space Complexity: O(N)
// Explanation: Use a stack of pairs `(price, span)`. When a new price comes in, initialize its span to 1. Pop elements from the stack while the top element's price is `<= price`, adding their spans to the current span. Push `(price, span)` to the stack.

class StockSpanner {
    stack<pair<int, int>> s;
public:
    StockSpanner() {}
    int next(int price) {
        int span = 1;
        while(!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

