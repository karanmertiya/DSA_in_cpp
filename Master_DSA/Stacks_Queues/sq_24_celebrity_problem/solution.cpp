// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a stack or two pointers. If using two pointers: `left = 0`, `right = N - 1`. If `knows(left, right)`, then `left` cannot be the celebrity, so `left++`. Else, `right` cannot be the celebrity, so `right--`. The remaining person `left` is a potential candidate. Verify by checking if `left` knows no one and everyone knows `left`.

int celebrity(vector<vector<int> >& M, int n) {
    int left = 0, right = n - 1;
    while(left < right) {
        if(M[left][right] == 1) left++;
        else right--;
    }
    for(int i = 0; i < n; i++) {
        if(i != left && (M[left][i] == 1 || M[i][left] == 0)) return -1;
    }
    return left;
}

