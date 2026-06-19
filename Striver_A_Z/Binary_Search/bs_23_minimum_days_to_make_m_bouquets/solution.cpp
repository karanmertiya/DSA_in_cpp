// Time Complexity: O(N log(max-min))
// Space Complexity: O(1)
// Explanation: If `m * k > n`, return -1. Search space for days is `[min(bloomDay), max(bloomDay)]`. For a `mid` day, count consecutive flowers that have bloomed (`bloomDay[i] <= mid`). If consecutive count reaches `k`, increment bouquet count. If `bouquets >= m`, move `high = mid - 1`, else `low = mid + 1`.

bool possible(vector<int>& arr, int day, int m, int k) {
    int n = arr.size(), cnt = 0, noOfB = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] <= day) cnt++;
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size();
    if(val > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    int low = mini, high = maxi;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(bloomDay, mid, m, k)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

