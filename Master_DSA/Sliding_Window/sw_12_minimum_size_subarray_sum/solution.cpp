// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a sliding window. Add elements to the current sum. While the sum is >= target, update the minimum length and shrink the window from the left.

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, sum = 0, minLen = INT_MAX;
    for(int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while(sum >= target) {
            minLen = min(minLen, r - l + 1);
            sum -= nums[l++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

