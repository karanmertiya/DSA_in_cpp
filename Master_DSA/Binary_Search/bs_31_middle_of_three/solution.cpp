// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int middle(int A, int B, int C) {
    if((A < B && B < C) || (C < B && B < A)) return B;
    if((B < A && A < C) || (C < A && A < B)) return A;
    return C;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Optimal: Compare the numbers. If A is between B and C, return A. If B is between A and C, return B. Else return C.

int middle(int A, int B, int C) {
    if((A < B && B < C) || (C < B && B < A)) return B;
    if((B < A && A < C) || (C < A && A < B)) return A;
    return C;
}

