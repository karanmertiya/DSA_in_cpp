// Time Complexity: O(log(M * N))
// Space Complexity: O(1)
// Explanation: Treat the 2D matrix as a 1D flattened array. The element at `index` is at `matrix[index / cols][index % cols]`. Perform standard binary search.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int val = matrix[mid / n][mid % n];
        if(val == target) return true;
        if(val < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

