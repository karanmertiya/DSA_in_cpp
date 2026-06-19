// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Search space is `[max(weights), sum(weights)]`. For a `mid` capacity, simulate loading the ship. If day count exceeds `days`, capacity is too small (`low = mid + 1`). Otherwise, try for a smaller capacity (`high = mid - 1`).

int findDays(vector<int>& weights, int cap) {
    int days = 1, load = 0;
    for(int i = 0; i < weights.size(); i++) {
        if(load + weights[i] > cap) {
            days++;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for(int w : weights) high += w;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(findDays(weights, mid) <= days) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

