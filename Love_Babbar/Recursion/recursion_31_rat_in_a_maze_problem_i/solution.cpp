// Time Complexity: O(4^(N*N))
// Space Complexity: O(N*N)
// Explanation: Start DFS from (0,0). Try D, L, R, U sequentially. If valid and not visited, mark visited, append direction to path, recurse, then unmark (backtrack) and pop direction. If reached (N-1, N-1), add path to results.

void solve(int i, int j, vector<vector<int>> &m, int n, vector<string>& ans, string move, vector<vector<int>> &vis) {
    if(i == n-1 && j == n-1) {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    for(int ind=0; ind<4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1) {
            vis[i][j] = 1;
            solve(nexti, nextj, m, n, ans, move + dir[ind], vis);
            vis[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if(m[0][0] == 1) solve(0, 0, m, n, ans, "", vis);
    return ans;
}

