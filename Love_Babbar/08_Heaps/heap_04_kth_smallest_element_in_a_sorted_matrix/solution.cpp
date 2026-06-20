// Time Complexity: O(N log(Max-Min))
// Space Complexity: O(1)
// Explanation: Binary search on the value range `[matrix[0][0], matrix[n-1][n-1]]`. Count elements less than or equal to `mid` using two pointers (start from bottom-left). If count >= k, search left half, else search right.

int countLessOrEqual(vector<vector<int>>& matrix, int mid, int n) {
    int count = 0, row = n - 1, col = 0;
    while(row >= 0 && col < n) {
        if(matrix[row][col] <= mid) { count += row + 1; col++; }
        else row--;
    }
    return count;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n-1][n-1];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(countLessOrEqual(matrix, mid, n) >= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

