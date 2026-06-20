// Time Complexity: O(log(min(A, B)))
// Space Complexity: O(1)
// Explanation: Use Euclidean algorithm. `gcd(A, B) = gcd(B, A % B)`. Repeat until `B` becomes 0, then `A` is the GCD.

int gcd(int A, int B) {
    while(A > 0 && B > 0) {
        if(A > B) A = A % B;
        else B = B % A;
    }
    if(A == 0) return B;
    return A;
}

