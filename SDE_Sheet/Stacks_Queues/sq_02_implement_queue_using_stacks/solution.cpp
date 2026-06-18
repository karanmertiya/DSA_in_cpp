// Time Complexity: O(1) Amortized
// Space Complexity: O(N)
// Explanation: Amortized O(1). Maintain an `input` stack for pushes and an `output` stack for pops. Only transfer elements when `output` is empty.

#include <stack>

class MyQueue {
    std::stack<int> input, output;
public:
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        peek();
        int val = output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

