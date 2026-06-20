// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Start from the top-right corner. If `target == current`, return true. If `target < current`, move left (`c--`). If `target > current`, move down (`r++`).

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = matrix[0].size() - 1;
    while(r < matrix.size() && c >= 0) {
        if(matrix[r][c] == target) return true;
        else if(matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

