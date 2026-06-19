// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: Iterative approach. Construct each row from the previous row. First and last elements are 1. Middle elements are sum of elements right above them.

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for(int i=0; i<numRows; i++) {
        vector<int> row(i+1, 1);
        for(int j=1; j<i; j++) {
            row[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(row);
    }
    return res;
}

