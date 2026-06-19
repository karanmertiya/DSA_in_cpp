// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: The inorder traversal of a BST is sorted. First, get the inorder traversal of the given complete binary tree using array indices. Then, the problem reduces to finding the minimum swaps to sort an array. Use graph cycles to find min swaps.

void inorder(vector<int>& a, vector<int>& v, int n, int index) {
    if(index >= n) return;
    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
int minSwaps(vector<int>& A, int n) {
    vector<int> v;
    inorder(A, v, n, 0);
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++) t[i] = {v[i], i};
    sort(t.begin(), t.end());
    int ans = 0;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(vis[i] || t[i].second == i) continue;
        int cycle_size = 0, j = i;
        while(!vis[j]) {
            vis[j] = true;
            j = t[j].second;
            cycle_size++;
        }
        if(cycle_size > 0) ans += (cycle_size - 1);
    }
    return ans;
}

