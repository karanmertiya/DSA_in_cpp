// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: 1. Find the largest index k such that nums[k] < nums[k + 1]. 2. Find the largest index l greater than k such that nums[k] < nums[l]. 3. Swap nums[k] and nums[l]. 4. Reverse the sub-array nums[k + 1:].

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k = -1, l = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) { k = i; break; }
    }
    if(k < 0) { reverse(nums.begin(), nums.end()); return; }
    for(int i = n - 1; i > k; i--) {
        if(nums[i] > nums[k]) { l = i; break; }
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
}

