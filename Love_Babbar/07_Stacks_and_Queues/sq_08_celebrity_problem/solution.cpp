// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Push all elements (0 to N-1) into a stack. Pop two elements `A` and `B`. If `A` knows `B`, `A` cannot be a celebrity, push `B` back. If `A` does not know `B`, `B` cannot be a celebrity, push `A` back. The remaining element is a potential celebrity. Verify it by checking if everyone knows it and it knows no one.

int celebrity(vector<vector<int> >& M, int n) {
    stack<int> st;
    for(int i = 0; i < n; i++) st.push(i);
    while(st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if(M[a][b] == 1) st.push(b);
        else st.push(a);
    }
    if(st.empty()) return -1;
    int pot = st.top();
    for(int i = 0; i < n; i++) {
        if(i != pot && (M[pot][i] == 1 || M[i][pot] == 0)) return -1;
    }
    return pot;
}

