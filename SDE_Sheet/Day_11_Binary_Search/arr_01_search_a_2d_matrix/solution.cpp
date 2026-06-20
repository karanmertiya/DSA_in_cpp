// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (m * n) - 1;
    while(low <= high) {
        int mid = (low + (high - low) / 2);
        if(matrix[mid/n][mid % n] == target) return true;
        if(matrix[mid/n][mid % n] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// Time Complexity: O(log(m * n))
// Space Complexity: O(1)
// Explanation: Optimal: Treat the 2D matrix as a 1D array and apply binary search. The element at `mid` can be accessed using `matrix[mid / cols][mid % cols]`.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (m * n) - 1;
    while(low <= high) {
        int mid = (low + (high - low) / 2);
        if(matrix[mid/n][mid % n] == target) return true;
        if(matrix[mid/n][mid % n] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

