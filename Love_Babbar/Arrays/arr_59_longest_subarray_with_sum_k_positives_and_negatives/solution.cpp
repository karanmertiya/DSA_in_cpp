// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a hash map to store the first occurrence of each prefix sum. While iterating, if `current_sum == K`, max length is `i+1`. If `current_sum - K` exists in the hash map, update max length with `i - map[current_sum - K]`. If `current_sum` is not in map, insert it.

int lenOfLongSubarr(int A[],  int N, int K) {
    unordered_map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(sum == K) maxLen = max(maxLen, i + 1);
        long long rem = sum - K;
        if(preSumMap.find(rem) != preSumMap.end()) {
            maxLen = max(maxLen, i - preSumMap[rem]);
        }
        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

