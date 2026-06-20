// Time Complexity: O(N)
// Space Complexity: O(log N) for recursion
// Explanation: Apply the standard max-heapify process starting from the last non-leaf node `(N/2 - 1)` down to the root. This takes O(N) time.

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void convertMinToMaxHeap(vector<int> &arr, int N) {
    for(int i = (N - 2) / 2; i >= 0; i--) {
        maxHeapify(arr, N, i);
    }
}

