// Time Complexity: O(N * log(sum(A) - max(A)))
// Space Complexity: O(1)
// Explanation: Optimal: Binary Search on Answer. The search space for pages is from `max(A)` to `sum(A)`. For a given `mid`, check if books can be allocated to `<= M` students without any student exceeding `mid` pages.

bool isPossible(int A[], int N, int M, int maxPages) {
    int students = 1, currentPages = 0;
    for(int i=0; i<N; i++) {
        if(A[i] > maxPages) return false;
        if(currentPages + A[i] > maxPages) {
            students++; currentPages = A[i];
        } else {
            currentPages += A[i];
        }
    }
    return students <= M;
}
int findPages(int A[], int N, int M) {
    if(M > N) return -1;
    int low = 0, high = 0, ans = -1;
    for(int i=0; i<N; i++) { low = max(low, A[i]); high += A[i]; }
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(A, N, M, mid)) {
            ans = mid; high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

