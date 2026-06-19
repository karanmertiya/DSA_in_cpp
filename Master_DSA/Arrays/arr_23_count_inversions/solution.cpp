// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Use Merge Sort. While merging two sorted halves, if `left[i] > right[j]`, then all elements from `left[i]` to `left[mid]` will form inversions with `right[j]`.

long long merge(long long arr[], long long temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv_count = 0;
    while(i <= mid - 1 && j <= right) {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else { temp[k++] = arr[j++]; inv_count = inv_count + (mid - i); }
    }
    while(i <= mid - 1) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    for(i = left; i <= right; i++) arr[i] = temp[i];
    return inv_count;
}
long long _mergeSort(long long arr[], long long temp[], int left, int right) {
    long long inv_count = 0;
    if(right > left) {
        int mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
long long int inversionCount(long long arr[], long long N) {
    long long temp[N];
    return _mergeSort(arr, temp, 0, N - 1);
}

