// Time Complexity: O(N)
// Space Complexity: O(N) recursive stack
// Explanation: Swap `arr[l]` and `arr[r]` and then recursively call `reverse(arr, l+1, r-1)`.

void reverseArray(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l + 1, r - 1);
}

