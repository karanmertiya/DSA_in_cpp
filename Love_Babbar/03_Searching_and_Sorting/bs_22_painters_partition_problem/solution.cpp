// Time Complexity: O(N log(Sum-Max))
// Space Complexity: O(1)
// Explanation: Optimal: Identical to Allocate Books and Split Array Largest Sum. Binary search `max(boards)` to `sum(boards)`.

int countPainters(vector<int>& boards, int time) {
    int painters = 1, boardsPainter = 0;
    for(int i=0; i<boards.size(); i++) {
        if(boardsPainter + boards[i] <= time) {
            boardsPainter += boards[i];
        } else {
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        int painters = countPainters(boards, mid);
        if(painters > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

