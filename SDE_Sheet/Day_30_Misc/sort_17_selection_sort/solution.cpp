// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Find the minimum element in the unsorted array and swap it with the element at the beginning.

#include <vector>
#include <utility>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

