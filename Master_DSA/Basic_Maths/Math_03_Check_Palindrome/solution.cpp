// --- Optimal Approach ---
// Time Complexity: O(log10(N)) (Constraint)
// Space Complexity: O(1) (Constraint)
// Edge Cases: <b>Variable Requirement:</b> Number is destroyed during loop, requires `dup` variable for final check.
// Note: Reverse the number mathematically and compare it to the original.

bool isPalindromeOptimal(int n) {
    // Edge Case: Negative numbers are strictly not palindromes
    if (n < 0) return false;
    
    int dup = n;
    long long revNum = 0;
    while(n > 0) {
        int ld = n % 10;
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }
    return dup == revNum;
}

