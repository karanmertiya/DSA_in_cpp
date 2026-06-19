// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: 1. Find largest index `k` such that `nums[k] < nums[k + 1]`. If no such index exists, the permutation is the last permutation, reverse it. 2. Find the largest index `l` greater than `k` such that `nums[k] < nums[l]`. 3. Swap `nums[k]` and `nums[l]`. 4. Reverse the sub-array `nums[k + 1:]`.

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k, l;
    for(k = n - 2; k >= 0; k--) {
        if(nums[k] < nums[k + 1]) break;
    }
    if(k < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        for(l = n - 1; l > k; l--) {
            if(nums[l] > nums[k]) break;
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

