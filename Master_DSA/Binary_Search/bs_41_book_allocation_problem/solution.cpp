// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Search space for max pages is `max(arr)` to `sum(arr)`. Use binary search. For a `mid` value, count how many students are needed. If `students > M`, we need to increase max pages (`low = mid + 1`), else we can try to decrease (`high = mid - 1`).

bool isPossible(int A[], int N, int M, long long mid) {
    int students = 1;
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        if(sum + A[i] > mid) {
            students++;
            sum = A[i];
            if(students > M || A[i] > mid) return false;
        } else {
            sum += A[i];
        }
    }
    return true;
}
int findPages(int A[], int N, int M) {
    if(M > N) return -1;
    long long sum = 0, mx = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        mx = max(mx, 1LL * A[i]);
    }
    long long low = mx, high = sum, ans = -1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(isPossible(A, N, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

