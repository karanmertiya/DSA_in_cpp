// Time Complexity: O(V^3)
// Space Complexity: O(V^2) or O(1) if in-place
// Explanation: Iterate `k` (via node) from 0 to V-1. Iterate `i` and `j`. `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`. If `matrix[i][i] < 0`, negative cycle exists.

void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
            if(i == j) matrix[i][j] = 0;
        }
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
        }
    }
}

