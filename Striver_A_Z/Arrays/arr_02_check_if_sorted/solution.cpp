// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Linearly traverse and ensure `arr[i] <= arr[i+1]`.

#include <vector>

bool isSorted(std::vector<int>& arr) {
    if (arr.size() <= 1) return true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

