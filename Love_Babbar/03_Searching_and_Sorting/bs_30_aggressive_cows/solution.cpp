// Time Complexity: O(N log N + N log(max_val))
// Space Complexity: O(1)
// Explanation: Sort array. Maximize the minimum distance. Search space from `1` to `max(arr) - min(arr)`. Function `isPossible(mid)` checks if we can place `K` cows such that distance between any two is at least `mid`.

bool isPossible(int stalls[], int n, int k, int mid) {
    int cows = 1, lastPos = stalls[0];
    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= mid) {
            cows++;
            lastPos = stalls[i];
            if(cows == k) return true;
        }
    }
    return false;
}
int solve(int n, int k, vector<int>& stalls) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0], ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(&stalls[0], n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

