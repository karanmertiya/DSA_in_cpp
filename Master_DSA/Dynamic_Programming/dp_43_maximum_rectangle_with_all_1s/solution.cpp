// Time Complexity: O(R * C)
// Space Complexity: O(C)
// Explanation: Treat each row as the base of a histogram. The height is the number of consecutive 1s going upwards. If a cell is 0, height is 0. For each row, after updating the heights, find the Largest Rectangle in Histogram (using a stack) and keep track of the maximum area overall.

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<int> heights(c, 0);
    int maxArea = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

