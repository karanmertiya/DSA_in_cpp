// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a sliding window. Expand the right pointer. If the element is 0, increment a zero counter. While the zero counter > k, shrink the window from the left by moving the left pointer and decrementing the zero counter if left element is 0. The max window size is the answer.

int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0, zeroes = 0, maxLen = 0;
    while(right < nums.size()) {
        if(nums[right] == 0) zeroes++;
        while(zeroes > k) {
            if(nums[left] == 0) zeroes--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

