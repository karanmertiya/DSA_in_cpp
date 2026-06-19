// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: Maintain a histogram for each row. The height of the histogram is the consecutive 1s ending at that cell. For each row's histogram, use the 'Largest Rectangle in Histogram' stack algorithm.

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxA = 0;
    for(int i=0; i<=n; i++) {
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, h * w);
        }
        st.push(i);
    }
    return maxA;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int maxArea = 0;
    vector<int> heights(matrix[0].size(), 0);
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

