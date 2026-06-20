// Time Complexity: O(N log M)
// Space Complexity: O(1)
// Explanation: Binary search on columns. Find middle column, find max element in this column. Compare it with its left and right neighbors. If it's > both, it's a peak. If left is greater, peak exists in left half. Else, peak exists in right half.

int maxElemRow(vector<vector<int>>& mat, int col) {
    int maxVal = -1, row = -1;
    for(int i=0; i<mat.size(); i++) {
        if(mat[i][col] > maxVal) {
            maxVal = mat[i][col];
            row = i;
        }
    }
    return row;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int row = maxElemRow(mat, mid);
        int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
        int right = mid + 1 < m ? mat[row][mid+1] : -1;
        if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
        else if(mat[row][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}

