// Time Complexity: O(2<sup>T</sup>) (Trade-off)
// Space Complexity: O(T) (Trade-off)
// Explanation: Pick/Non-Pick but when picking, we *do not* increment the index `i`, allowing the same element to be picked infinitely until `target < 0`.

#include <vector>

void solve(int i, std::vector<int>& arr, int target, std::vector<int>& temp, std::vector<std::vector<int>>& ans) {
    if (i == arr.size()) {
        if (target == 0) ans.push_back(temp);
        return;
    }
    // Pick (Stay on same index if valid)
    if (arr[i] <= target) {
        temp.push_back(arr[i]);
        solve(i, arr, target - arr[i], temp, ans);
        temp.pop_back();
    }
    // Not Pick (Move to next)
    solve(i + 1, arr, target, temp, ans);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    solve(0, candidates, target, temp, ans);
    return ans;
}

