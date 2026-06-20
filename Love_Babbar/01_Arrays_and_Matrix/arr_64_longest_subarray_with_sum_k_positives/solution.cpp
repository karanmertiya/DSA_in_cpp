// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int lenOfLongSubarr(int A[],  int N, int K) {
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    while(right < N) {
        sum += A[right];
        while(sum > K && left <= right) {
            sum -= A[left];
            left++;
        }
        if(sum == K) maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Since all elements are positive, use two pointers (sliding window). Expand `right` and add to sum. If sum > K, shrink `left` and subtract from sum. If sum == K, update max length.

int lenOfLongSubarr(int A[],  int N, int K) {
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    while(right < N) {
        sum += A[right];
        while(sum > K && left <= right) {
            sum -= A[left];
            left++;
        }
        if(sum == K) maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

