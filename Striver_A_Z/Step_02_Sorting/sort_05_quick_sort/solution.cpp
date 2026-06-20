// Time Complexity: O(N log N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Pick a pivot. Place smaller elements left and larger right. Recursively sort partitions.

#include <vector>
#include <utility>

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

void quickSortHelper(std::vector<int>& arr, int low, int high) {
    if(low < high) {
        int pIndex = partition(arr, low, high);
        quickSortHelper(arr, low, pIndex - 1);
        quickSortHelper(arr, pIndex + 1, high);
    }
}

void quickSort(std::vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

