// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a stack to find Next Smaller Element (NSE) and Previous Smaller Element (PSE) for each bar. Then, the width of the rectangle with bar `i` as the minimum height is `NSE[i] - PSE[i] - 1`. The area is `height[i] * width`.

long long getMaxArea(long long arr[], int n) {
    stack<int> st;
    long long max_area = 0;
    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
            long long height = arr[st.top()];
            st.pop();
            long long width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        st.push(i);
    }
    return max_area;
}

