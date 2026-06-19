// Time Complexity: O(N log N) Avg, O(N<sup>2</sup>) Worst
// Space Complexity: O(log N)
// Explanation: Divide and Conquer. Pick a pivot (e.g., first element), partition elements smaller to the left and larger to the right. Recurse.

#include <vector>
#include <algorithm>
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1) i++;
        while(arr[j] > pivot && j >= low + 1) j--;
        if(i < j) std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}
void quickSort(std::vector<int>& arr, int low, int high) {
    if(low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

