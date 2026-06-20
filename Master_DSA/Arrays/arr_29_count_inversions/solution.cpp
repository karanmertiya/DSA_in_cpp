// Time Complexity: O(N log N)
// Space Complexity: O(N) auxiliary
// Explanation: Optimal: Merge Sort approach. While merging two sorted halves, if left[i] > right[j], it forms an inversion with all remaining elements in the left half (mid - i + 1).

long long merge(long long arr[], int low, int mid, int high) {
    vector<long long> temp;
    int left = low, right = mid + 1;
    long long cnt = 0;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else { temp.push_back(arr[right++]); cnt += (mid - left + 1); }
    }
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);
    for(int i=low; i<=high; i++) arr[i] = temp[i - low];
    return cnt;
}
long long mergeSort(long long arr[], int low, int high) {
    long long cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
long long int inversionCount(long long arr[], long long N) {
    return mergeSort(arr, 0, N - 1);
}

