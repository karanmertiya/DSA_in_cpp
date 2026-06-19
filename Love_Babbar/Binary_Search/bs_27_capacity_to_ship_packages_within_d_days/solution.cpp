// Time Complexity: O(N log(Sum-Max))
// Space Complexity: O(1)
// Explanation: Binary search for capacity from `max(weights)` to `sum(weights)`. For a capacity `mid`, calculate days required to ship. If required days <= D, move `high = mid - 1`, else `low = mid + 1`.

int findDays(vector<int>& weights, int cap) {
    int days = 1, load = 0;
    for(int i=0; i<weights.size(); i++) {
        if(load + weights[i] > cap) {
            days += 1;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(findDays(weights, mid) <= days) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

