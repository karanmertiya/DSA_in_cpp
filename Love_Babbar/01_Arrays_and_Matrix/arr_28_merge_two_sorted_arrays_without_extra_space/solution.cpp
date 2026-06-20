// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
void merge(long long arr1[], long long arr2[], int n, int m) {
    int left = n - 1, right = 0;
    while(left >= 0 && right < m) {
        if(arr1[left] > arr2[right]) { swap(arr1[left], arr2[right]); left--; right++; }
        else break;
    }
    sort(arr1, arr1 + n); sort(arr2, arr2 + m);
}

// Time Complexity: O((N+M) log(N+M))
// Space Complexity: O(1)
// Explanation: Optimal: Start pointers at end of arr1 (i) and beginning of arr2 (j). Swap if arr1[i] > arr2[j]. Afterwards, individually sort arr1 and arr2. Time is bounded by sorting.

void merge(long long arr1[], long long arr2[], int n, int m) {
    int left = n - 1, right = 0;
    while(left >= 0 && right < m) {
        if(arr1[left] > arr2[right]) { swap(arr1[left], arr2[right]); left--; right++; }
        else break;
    }
    sort(arr1, arr1 + n); sort(arr2, arr2 + m);
}

