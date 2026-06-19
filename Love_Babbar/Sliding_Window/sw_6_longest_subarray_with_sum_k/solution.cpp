// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Keep track of the prefix sum. Store the first occurrence of each prefix sum in a hash map. If `prefix_sum - K` exists in the hash map, calculate the length of the subarray and update the maximum length.

int lenOfLongSubarr(int A[],  int N, int K) {
    unordered_map<int, int> preSum;
    int sum = 0, maxLen = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(sum == K) maxLen = max(maxLen, i + 1);
        if(preSum.find(sum - K) != preSum.end()) {
            maxLen = max(maxLen, i - preSum[sum - K]);
        }
        if(preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
        }
    }
    return maxLen;
}

