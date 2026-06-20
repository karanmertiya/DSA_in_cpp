// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
bool isPalindrome(int N) {
    int rev = 0, temp = N;
    while(temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == N;
}
int PalinArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(!isPalindrome(a[i])) return 0;
    }
    return 1;
}

// Time Complexity: O(N * d)
// Space Complexity: O(1)
// Explanation: Optimal: Iterate through each number in the array. For each number, reverse its digits to check if it's a palindrome. If any number is not, return 0. If all are, return 1.

bool isPalindrome(int N) {
    int rev = 0, temp = N;
    while(temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == N;
}
int PalinArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(!isPalindrome(a[i])) return 0;
    }
    return 1;
}

