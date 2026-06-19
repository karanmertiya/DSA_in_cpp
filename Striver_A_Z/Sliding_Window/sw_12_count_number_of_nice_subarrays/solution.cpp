// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Replace all odd numbers with 1 and even numbers with 0. The problem then reduces to finding the number of subarrays with a sum equal to k. Use the `atMost(k) - atMost(k - 1)` sliding window approach.

int atMost(vector<int>& nums, int k) {
    if(k < 0) return 0;
    int left = 0, count = 0, res = 0;
    for(int right = 0; right < nums.size(); right++) {
        if(nums[right] % 2 != 0) count++;
        while(count > k) {
            if(nums[left] % 2 != 0) count--;
            left++;
        }
        res += (right - left + 1);
    }
    return res;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

