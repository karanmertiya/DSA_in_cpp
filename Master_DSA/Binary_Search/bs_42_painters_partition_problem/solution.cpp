// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Similar to Book Allocation. Find if it's possible to paint all boards within `mid` time using at most `K` painters. Search space from `max(arr)` to `sum(arr)`.

bool isPossible(int arr[], int n, int k, long long mid) {
    int painters = 1;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + arr[i] > mid) {
            painters++;
            sum = arr[i];
            if(painters > k || arr[i] > mid) return false;
        } else {
            sum += arr[i];
        }
    }
    return true;
}
long long minTime(int arr[], int n, int k) {
    long long low = 0, high = 0, ans = -1;
    for(int i = 0; i < n; i++) {
        low = max(low, 1LL * arr[i]);
        high += arr[i];
    }
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

