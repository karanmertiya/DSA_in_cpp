// Time Complexity: O(N * W)
// Space Complexity: O(W)
// Explanation: 2D DP or 1D array space-optimized DP. Check take and not-take scenarios.

int knapSack(int W, int wt[], int val[], int n) {
    vector<int> prev(W + 1, 0);
    for(int w = wt[0]; w <= W; w++) prev[w] = val[0];
    for(int ind = 1; ind < n; ind++) {
        for(int w = W; w >= 0; w--) {
            int notTake = prev[w];
            int take = INT_MIN;
            if(wt[ind] <= w) take = val[ind] + prev[w - wt[ind]];
            prev[w] = max(take, notTake);
        }
    }
    return prev[W];
}

