// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: This is known as the digital root. The formula is `1 + (n - 1) % 9`. If `n == 0`, return `0`.

int addDigits(int num) {
    if(num == 0) return 0;
    return 1 + (num - 1) % 9;
}

