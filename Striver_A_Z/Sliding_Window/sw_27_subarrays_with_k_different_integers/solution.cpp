// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Exact K = At Most K - At Most K-1. Use a helper function `atMost(nums, k)` that uses a sliding window to count subarrays with at most `k` distinct integers.

int atMost(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int left = 0, count = 0;
    for(int right = 0; right < nums.size(); right++) {
        if(m[nums[right]] == 0) k--;
        m[nums[right]]++;
        while(k < 0) {
            m[nums[left]]--;
            if(m[nums[left]] == 0) k++;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

