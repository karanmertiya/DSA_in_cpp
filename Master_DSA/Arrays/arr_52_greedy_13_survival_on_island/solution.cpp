// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Optimal: If total required food > max food you can buy in S days excluding Sundays, return -1. Else, total required food is `S * M`. Minimum days = `ceil((S * M) / N)`. Also handle the edge case where `N < M` or if survival > 6 days and `(N * 6) < (M * 7)`.

int minimumDays(int S, int N, int M) {
    if(M > N) return -1;
    if(S > 6 && (N * 6) < (M * 7)) return -1;
    int total = S * M;
    return ceil((double)total / N);
}

