// Time Complexity: O(N log N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Recursively split array in half, sort them, and merge the sorted halves.

#include <vector>

void merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> temp;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);
    for(int i = low; i <= high; i++) arr[i] = temp[i - low];
}

void mergeSortHelper(std::vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSortHelper(arr, low, mid);
    mergeSortHelper(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(std::vector<int>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

