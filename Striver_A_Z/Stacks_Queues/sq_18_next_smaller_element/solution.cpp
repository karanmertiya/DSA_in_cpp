// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Iterate from right to left. Use a monotonic stack. Pop elements from the stack that are greater than or equal to the current element. The top of the stack is the next smaller element. Push the current element to the stack.

vector<int> help_classmate(vector<int> arr, int n) {
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() >= arr[i]) s.pop();
        if(!s.empty()) ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

