// Time Complexity: O(R * C)
// Space Complexity: O(C)
// Explanation: Treat each row as the base of a histogram. Calculate heights for each row (`heights[j]++` if `matrix[i][j]=='1'`, else `0`). Then compute Largest Rectangle in Histogram for each row and take the maximum.

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<int> heights(c, 0);
    int maxArea = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
        }
        stack<int> st;
        for(int j = 0; j <= c; j++) {
            int h = (j == c) ? 0 : heights[j];
            while(!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(j);
        }
    }
    return maxArea;
}

