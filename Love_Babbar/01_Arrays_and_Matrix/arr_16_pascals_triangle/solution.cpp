// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
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

// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(N<sup>2</sup>) (Constraint)
// Explanation: Optimal: Generate row by row. Each element `val[i][j]` is the sum of `val[i-1][j-1]` and `val[i-1][j]`.

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

