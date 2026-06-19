// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a sliding window. Add elements to `sum`. While `sum >= target`, update `min_len` and subtract `nums[left]` from `sum`, incrementing `left`.

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, minLen = INT_MAX, sum = 0;
    for(int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while(sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

