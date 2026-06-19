// Time Complexity: O(N! * N)
// Space Complexity: O(N!)
// Explanation: Iterate from index `i` to `n-1`. Swap `str[i]` with `str[j]`, then recursively call for the next index. After returning, swap back to backtrack. Store permutations in a set or sort the array to handle duplicates and lexicographical order.

void solve(string S, int idx, set<string>& st) {
    if(idx == S.length()) {
        st.insert(S);
        return;
    }
    for(int i = idx; i < S.length(); i++) {
        swap(S[idx], S[i]);
        solve(S, idx + 1, st);
        swap(S[idx], S[i]);
    }
}
vector<string> find_permutation(string S) {
    set<string> st;
    solve(S, 0, st);
    vector<string> ans(st.begin(), st.end());
    return ans;
}

