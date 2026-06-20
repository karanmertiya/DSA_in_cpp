// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int minSwap(int arr[], int n, int k) {
    int cnt = 0;
    for(int i = 0; i < n; i++) if(arr[i] <= k) cnt++;
    int bad = 0;
    for(int i = 0; i < cnt; i++) if(arr[i] > k) bad++;
    int ans = bad;
    for(int i = 0, j = cnt; j < n; i++, j++) {
        if(arr[i] > k) bad--;
        if(arr[j] > k) bad++;
        ans = min(ans, bad);
    }
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: First count all elements <= k (let's say `cnt`). This will be the window size. Find elements > k in the first window. Then slide the window, updating the number of elements > k. The minimum among all windows is the answer.

int minSwap(int arr[], int n, int k) {
    int cnt = 0;
    for(int i = 0; i < n; i++) if(arr[i] <= k) cnt++;
    int bad = 0;
    for(int i = 0; i < cnt; i++) if(arr[i] > k) bad++;
    int ans = bad;
    for(int i = 0, j = cnt; j < n; i++, j++) {
        if(arr[i] > k) bad--;
        if(arr[j] > k) bad++;
        ans = min(ans, bad);
    }
    return ans;
}

