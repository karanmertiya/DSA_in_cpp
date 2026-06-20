// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Instead of linear search, we can jump ahead. The minimum jump we can make from index `i` to reach `x` is `abs(arr[i] - x) / k`. We jump this amount and check if we found it. Make sure jump is at least 1.

int search(int arr[], int n, int x, int k) {
    int i = 0;
    while(i < n) {
        if(arr[i] == x) return i;
        i = i + max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

