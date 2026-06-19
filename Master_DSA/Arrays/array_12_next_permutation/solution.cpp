// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Find first dip from right (i). Find element just larger than nums[i] from right (j). Swap them and reverse the array from i+1 to end.

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k, l;
    for(k = n - 2; k >= 0; k--) if(nums[k] < nums[k+1]) break;
    if(k < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        for(l = n - 1; l > k; l--) if(nums[l] > nums[k]) break;
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

