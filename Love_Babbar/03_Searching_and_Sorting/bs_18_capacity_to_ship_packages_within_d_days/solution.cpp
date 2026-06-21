// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Optimal: Binary search on capacity. Low = `max(weights)`, High = `sum(weights)`. Iterate through packages and accumulate weight, increment day if limit is exceeded.

bool canShip(vector<int>& weights, int days, int cap) {
    int d = 1, load = 0;
    for(int w : weights) {
        if(load + w > cap) { d++; load = w; }
        else load += w;
    }
    return d <= days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = 0, high = 0;
    for(int w : weights) { low = max(low, w); high += w; }
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canShip(weights, days, mid)) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

