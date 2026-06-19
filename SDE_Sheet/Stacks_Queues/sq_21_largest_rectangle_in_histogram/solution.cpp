// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a stack to keep track of the indices of the bars in increasing order of height. If the current bar is shorter than the top of the stack, pop bars and calculate the area for each popped bar as the shortest bar. The width is `i - stack.top() - 1`. If stack is empty, width is `i`.

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), maxArea = 0;
    stack<int> s;
    for(int i = 0; i <= n; i++) {
        while(!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

