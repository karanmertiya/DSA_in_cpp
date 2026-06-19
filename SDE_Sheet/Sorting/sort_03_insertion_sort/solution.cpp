// Time Complexity: O(N<sup>2</sup>) (Constraint)
// Space Complexity: O(1)
// Explanation: Takes an element and places it in its correct position within the previously sorted part of the array.

#include <vector>
#include <utility>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

