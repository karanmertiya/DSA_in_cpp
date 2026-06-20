// Time Complexity: O(L * log(max_time))
// Space Complexity: O(1)
// Explanation: Optimal: Search space is `0` to `max_time`, where `max_time` is the time taken by the fastest cook to make all `P` pratas alone. `isPossible(mid)` checks if the total pratas made by all cooks in `mid` time is at least `P`.

bool isPossible(vector<int>& rank, int p, int mid) {
    int count = 0;
    for(int r : rank) {
        int time = 0, j = 1;
        while(time + r * j <= mid) {
            count++;
            time += r * j;
            j++;
        }
        if(count >= p) return true;
    }
    return count >= p;
}
int minTime(int p, vector<int>& rank) {
    int low = 0, high = 1e8, ans = -1; // high could be rank[0] * P * (P+1) / 2
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(rank, p, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

