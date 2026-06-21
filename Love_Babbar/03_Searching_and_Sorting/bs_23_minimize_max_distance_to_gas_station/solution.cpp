// Time Complexity: O(N log(MaxDist / 1e-6))
// Space Complexity: O(1)
// Explanation: Optimal: Binary search on the real answer (distance) with a precision (e.g., 1e-6). For a given `mid` distance, count how many gas stations need to be inserted in each gap: `ceil((stations[i+1] - stations[i]) / mid) - 1`. If total needed > k, `low = mid`, else `high = mid`.

int numberOfGasStationsRequired(double dist, vector<int>& arr) {
    int n = arr.size(), cnt = 0;
    for(int i=1; i<n; i++) {
        int numberInBetween = ((arr[i] - arr[i-1]) / dist);
        if((arr[i] - arr[i-1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    double low = 0;
    double high = 0;
    for(int i=0; i<n-1; i++) high = max(high, (double)(stations[i+1] - stations[i]));
    double diff = 1e-6;
    while(high - low > diff) {
        double mid = low + (high - low) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, stations);
        if(cnt > k) low = mid;
        else high = mid;
    }
    return high;
}

