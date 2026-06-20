// Time Complexity: O(log10 N)
// Space Complexity: O(1)
// Explanation: Convert to string and return length, or repeatedly divide by 10. O(log10 N) time.

int evenlyDivides(int N){
    if (N == 0) return 1;
    int count = 0, temp = N;
    while(temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && N % digit == 0) count++;
        temp /= 10;
    }
    return count;
}

