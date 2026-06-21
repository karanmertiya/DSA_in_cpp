// Time Complexity: O(N log(maxD - minD))
// Space Complexity: O(1)
// Explanation: Optimal: Binary search on days from `min(bloom)` to `max(bloom)`. Count consecutive bloomed flowers, if it reaches `k`, form a bouquet. Return minimum valid day.

bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
    int count = 0, bouquets = 0;
    for(int d : bloomDay) {
        if(d <= day) count++;
        else {
            bouquets += count / k;
            count = 0;
        }
    }
    bouquets += count / k;
    return bouquets >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    if((long long)m * k > bloomDay.size()) return -1;
    int low = 1e9, high = 0;
    for(int d : bloomDay) { low = min(low, d); high = max(high, d); }
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(bloomDay, m, k, mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    return ans;
}

