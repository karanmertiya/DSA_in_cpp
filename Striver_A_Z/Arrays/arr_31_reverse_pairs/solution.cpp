// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Modified Merge Sort. Before merging, loop through left and right halves. If left[i] > 2 * right[j], increment j. Number of pairs is (j - (mid+1)).

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);
    for(int i=low; i<=high; i++) arr[i] = temp[i - low];
}
int countPairs(vector<int>& arr, int low, int mid, int high) {
    int right = mid + 1, cnt = 0;
    for(int i = low; i <= mid; i++) {
        while(right <= high && arr[i] > 2LL * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int>& arr, int low, int high) {
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}
int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

