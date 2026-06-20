// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int missingNumber(vector<int>& array, int n) {
    long long sum = 0;
    for(int i = 0; i < n - 1; i++) sum += array[i];
    long long expectedSum = (long long)n * (n + 1) / 2;
    return expectedSum - sum;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Calculate the sum of first N natural numbers using `N*(N+1)/2`. Subtract the sum of all elements in the array from it. The result is the missing number.

int missingNumber(vector<int>& array, int n) {
    long long sum = 0;
    for(int i = 0; i < n - 1; i++) sum += array[i];
    long long expectedSum = (long long)n * (n + 1) / 2;
    return expectedSum - sum;
}

