// Time Complexity: O(N * K * log K)
// Space Complexity: O(K)
// Explanation: Maintain a min-heap of size K, storing the first element of each list along with its list index and element index. Keep track of the `max_val` currently in the heap. The current range is `[heap_min, max_val]`. Extract the min, update the smallest range if needed, and insert the next element from the extracted element's list. Update `max_val` with the new element.

pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int mx = INT_MIN;
    for(int i = 0; i < k; i++) {
        pq.push({KSortedArray[i][0], i, 0});
        mx = max(mx, KSortedArray[i][0]);
    }
    int range = INT_MAX, start = -1, end = -1;
    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int mn = curr[0];
        int row = curr[1], col = curr[2];
        if(mx - mn < range) {
            range = mx - mn;
            start = mn; end = mx;
        }
        if(col + 1 < n) {
            pq.push({KSortedArray[row][col+1], row, col+1});
            mx = max(mx, KSortedArray[row][col+1]);
        } else {
            break;
        }
    }
    return {start, end};
}

