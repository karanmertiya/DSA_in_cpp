// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Iterate from right to left. Use a stack to keep track of elements. Pop from the stack while the top element is less than or equal to the current element. If stack is empty, NGE is -1, else it's the stack top. Push current element.

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> res(n);
    stack<long long> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(arr[i]);
    }
    return res;
}

