// Time Complexity: O(1) Math, O(N) Recursion
// Space Complexity: O(1) Math, O(N) Recursion
// Explanation: The mathematical formula for the sum of cubes is `(n * (n + 1) / 2)^2`. Alternatively, use recursion `f(n) = n^3 + f(n-1)`.

long long sumOfSeries(long long n) {
    return (n * (n + 1) / 2) * (n * (n + 1) / 2);
}

