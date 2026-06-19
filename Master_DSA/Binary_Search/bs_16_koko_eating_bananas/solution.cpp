// Time Complexity: O(N log(max(P)))
// Space Complexity: O(1)
// Explanation: Binary search on the answer. Minimum speed is 1, maximum is `max(piles)`. For a given speed `mid`, calculate total hours `sum(ceil(pile / mid))`. If `<= h`, search lower half.

long long getHours(vector<int>& piles, int speed) {
    long long totalHours = 0;
    for(int p : piles) totalHours += ceil((double)p / speed);
    return totalHours;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = 0;
    for(int p : piles) high = max(high, p);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(getHours(piles, mid) <= h) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

