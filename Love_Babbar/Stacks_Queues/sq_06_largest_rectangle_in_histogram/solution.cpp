// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), maxArea = 0;
    stack<int> st;
    for(int i=0; i<=n; i++) {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, width * height);
        }
        st.push(i);
    }
    return maxArea;
}

