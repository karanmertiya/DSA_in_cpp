// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Sort intervals based on start time. Push first interval to stack. For each subsequent interval, if it overlaps with the stack top, pop the stack top, merge the two, and push back. Else, push it to stack.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    stack<vector<int>> st;
    st.push(intervals[0]);
    for(int i = 1; i < intervals.size(); i++) {
        vector<int> top = st.top();
        if(top[1] >= intervals[i][0]) {
            st.pop();
            top[1] = max(top[1], intervals[i][1]);
            st.push(top);
        } else {
            st.push(intervals[i]);
        }
    }
    vector<vector<int>> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

