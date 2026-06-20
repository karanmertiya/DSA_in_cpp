// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(N<sup>2</sup>) (Constraint)
// Explanation: Generate row by row. Each element `val[i][j]` is the sum of `val[i-1][j-1]` and `val[i-1][j]`.

#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans(numRows);
    for(int i = 0; i < numRows; i++) {
        ans[i].resize(i + 1, 1);
        for(int j = 1; j < i; j++) {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}

