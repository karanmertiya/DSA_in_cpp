// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Convert '0' to 1 and '1' to -1. Find the maximum subarray sum using Kadane's algorithm. If max sum is negative, it means string has all 1s, return -1.

int maxSubstring(string S) {
    int mx = INT_MIN, curr = 0;
    for(char c : S) {
        int val = c == '0' ? 1 : -1;
        curr = max(val, curr + val);
        mx = max(mx, curr);
    }
    return mx;
}

