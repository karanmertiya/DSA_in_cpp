// Time Complexity: O(N * K log K)
// Space Complexity: O(K)
// Explanation: Similar to merging K sorted arrays, use a Min Heap storing `(value, list_idx, element_idx)`. Also maintain the `max_val` seen so far among the current elements. The range is `[min_heap_top, max_val]`. Update the range if the difference is smaller. Pop the min and push the next element from the same list, updating `max_val`.

pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int max_val = INT_MIN, range_min = INT_MAX, range_max = INT_MAX, range = INT_MAX;
    for(int i = 0; i < k; i++) {
        pq.push({KSortedArray[i][0], {i, 0}});
        max_val = max(max_val, KSortedArray[i][0]);
    }
    while(true) {
        auto curr = pq.top(); pq.pop();
        int min_val = curr.first, r = curr.second.first, c = curr.second.second;
        if(max_val - min_val < range) {
            range = max_val - min_val;
            range_min = min_val;
            range_max = max_val;
        }
        if(c + 1 == n) break;
        pq.push({KSortedArray[r][c + 1], {r, c + 1}});
        max_val = max(max_val, KSortedArray[r][c + 1]);
    }
    return {range_min, range_max};
}

