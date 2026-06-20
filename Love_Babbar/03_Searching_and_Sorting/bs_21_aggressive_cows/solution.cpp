// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
bool canWePlace(vector<int>& stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for(int i=1; i<n; i++) {
        if(stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
    }
    return cntCows >= cows;
}
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canWePlace(stalls, mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

// Time Complexity: O(N log N + N log(Max-Min))
// Space Complexity: O(1)
// Explanation: Optimal: Sort the stalls. Binary search for distance from `1` to `max-min`. For a distance `mid`, check if we can place all `C` cows such that distance between any two is >= `mid`. If possible, move `low = mid + 1` to maximize it, else `high = mid - 1`.

bool canWePlace(vector<int>& stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for(int i=1; i<n; i++) {
        if(stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
    }
    return cntCows >= cows;
}
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canWePlace(stalls, mid, k)) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

