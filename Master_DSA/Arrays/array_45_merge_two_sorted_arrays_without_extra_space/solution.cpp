// Time Complexity: O((N + M) log(N + M))
// Space Complexity: O(1)
// Explanation: Use the Gap method. Initial gap is `ceil((n + m) / 2)`. Iterate with two pointers separated by `gap`. If `left` and `right` elements are out of order, swap them. Reduce `gap` by `ceil(gap / 2)` until `gap == 0`.

void merge(long long arr1[], long long arr2[], int n, int m) {
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while(gap > 0) {
        int left = 0, right = left + gap;
        while(right < len) {
            int arr1Left = left < n ? arr1[left] : arr2[left - n];
            int arr2Right = right < n ? arr1[right] : arr2[right - n];
            if(arr1Left > arr2Right) {
                if(left < n && right < n) swap(arr1[left], arr1[right]);
                else if(left < n && right >= n) swap(arr1[left], arr2[right - n]);
                else swap(arr2[left - n], arr2[right - n]);
            }
            left++; right++;
        }
        if(gap <= 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

