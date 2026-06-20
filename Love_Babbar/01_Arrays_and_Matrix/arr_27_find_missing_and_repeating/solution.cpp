// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
vector<int> findTwoElement(vector<int> arr, int n) {
    long long N = n;
    long long S_N = (N * (N+1)) / 2;
    long long Sq_N = (N * (N+1) * (2*N+1)) / 6;
    long long S = 0, Sq = 0;
    for(int i=0; i<N; i++) {
        S += arr[i]; Sq += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S_N - S; // X - Y
    long long val2 = Sq_N - Sq; // X^2 - Y^2
    val2 = val2 / val1; // X + Y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)y, (int)x};
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Mathematical approach. Diff = Sum_N - Sum_Arr = Missing - Repeating. SumSqDiff = SumSq_N - SumSq_Arr = Missing^2 - Repeating^2. Use formulas to solve for both.

vector<int> findTwoElement(vector<int> arr, int n) {
    long long N = n;
    long long S_N = (N * (N+1)) / 2;
    long long Sq_N = (N * (N+1) * (2*N+1)) / 6;
    long long S = 0, Sq = 0;
    for(int i=0; i<N; i++) {
        S += arr[i]; Sq += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S_N - S; // X - Y
    long long val2 = Sq_N - Sq; // X^2 - Y^2
    val2 = val2 / val1; // X + Y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)y, (int)x};
}

