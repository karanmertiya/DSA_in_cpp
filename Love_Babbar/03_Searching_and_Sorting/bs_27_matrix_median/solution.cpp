// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int countSmallerThanMid(vector<int>& row, int mid) {
    int l = 0, h = row.size() - 1;
    while(l <= h) {
        int md = (l + h) / 2;
        if(row[md] <= mid) l = md + 1;
        else h = md - 1;
    }
    return l;
}
int findMedian(vector<vector<int> > &A) {
    int low = 1, high = 1e9;
    int n = A.size(), m = A[0].size();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += countSmallerThanMid(A[i], mid);
        }
        if(cnt <= (n * m) / 2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

// Time Complexity: O(32 * N log M)
// Space Complexity: O(1)
// Explanation: Optimal: Binary search on the value range `[1, 10^9]`. For a candidate `mid`, count how many numbers are `<= mid` across all rows using `upper_bound`. If count `> (N*M)/2`, `mid` could be median, search lower. Else search higher.

int countSmallerThanMid(vector<int>& row, int mid) {
    int l = 0, h = row.size() - 1;
    while(l <= h) {
        int md = (l + h) / 2;
        if(row[md] <= mid) l = md + 1;
        else h = md - 1;
    }
    return l;
}
int findMedian(vector<vector<int> > &A) {
    int low = 1, high = 1e9;
    int n = A.size(), m = A[0].size();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += countSmallerThanMid(A[i], mid);
        }
        if(cnt <= (n * m) / 2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

