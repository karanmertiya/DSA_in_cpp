// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Binary search on capacity `[max(weights), sum(weights)]`. For a `mid` capacity, greedily load packages. If a package makes sum > capacity, increment days and start new load. If `days <= D`, search left. Else search right.

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for(int w : weights) high += w;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int d = 1, load = 0;
        for(int w : weights) {
            if(load + w > mid) {
                d++;
                load = w;
            } else {
                load += w;
            }
        }
        if(d <= days) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

