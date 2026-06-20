// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Convert the number to a string and return its length.

int countDigits(int n) {
    return to_string(n).length();
}

// Time Complexity: O(log10 N)
// Space Complexity: O(1)
// Explanation: Use a while loop to repeatedly divide the number by 10 and increment a counter.

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Use the base-10 logarithm function to find the number of digits mathematically.

int countDigits(int n) {
    if (n == 0) return 1;
    return (int)(log10(n) + 1);
}

