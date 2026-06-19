// Time Complexity: O(N + M)
// Space Complexity: O(N + M)
// Explanation: Create a new array by appending the two arrays. Then call `heapify` starting from the last non-leaf node `(n/2 - 1)` down to the root `0`.

void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> ans;
    for(int i : a) ans.push_back(i);
    for(int i : b) ans.push_back(i);
    int total = n + m;
    for(int i = total / 2 - 1; i >= 0; i--) {
        heapify(ans, total, i);
    }
    return ans;
}

