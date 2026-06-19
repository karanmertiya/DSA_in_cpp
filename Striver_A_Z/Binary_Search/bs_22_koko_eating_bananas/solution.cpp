// Time Complexity: O(N log(max(piles)))
// Space Complexity: O(1)
// Explanation: Search space for speed `k` is `[1, max(piles)]`. For a chosen `mid` speed, calculate the total hours needed. If `total_hours <= h`, this `mid` is a possible answer, search left for smaller speed. Else search right.

long long calculateTotalHours(vector<int>& v, int hourly) {
    long long totalH = 0;
    for(int i = 0; i < v.size(); i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while(low <= high) {
        int mid = low + (high - low) / 2;
        long long totalH = calculateTotalHours(piles, mid);
        if(totalH <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

