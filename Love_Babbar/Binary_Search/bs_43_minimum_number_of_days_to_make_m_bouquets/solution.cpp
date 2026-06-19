// Time Complexity: O(N log(max_day))
// Space Complexity: O(1)
// Explanation: If `m * k > n`, return -1. Binary search on days `[min(bloomDay), max(bloomDay)]`. For a given day, count adjacent bloomed flowers. Every `k` consecutive bloomed flowers make 1 bouquet. If total bouquets >= m, search left. Else search right.

int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = 1LL * m * k;
    if(val > bloomDay.size()) return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int bouquets = 0, count = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                count++;
                if(count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        if(bouquets >= m) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

