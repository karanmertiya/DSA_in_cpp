// Time Complexity: O(N<sup>2</sup>) (Trade-off)
// Space Complexity: O(1)
// Explanation: Repeatedly swap adjacent elements if they are in the wrong order. Push the maximum element to the end.

#include <vector>
#include <utility>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i >= 1; i--) {
        bool did_swap = false;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                did_swap = true;
            }
        }
        if (!did_swap) break;
    }
}

