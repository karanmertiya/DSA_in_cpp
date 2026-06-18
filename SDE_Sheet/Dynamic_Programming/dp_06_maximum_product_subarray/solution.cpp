// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Prefix and Suffix product approach. Calculate product from left to right and right to left. Reset product to 1 when a zero is encountered.

int maxProduct(std::vector<int>& nums) {
    int max_prod = INT_MIN, n = nums.size();
    int pref = 1, suff = 1;
    for(int i = 0; i < n; i++) {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= nums[i];
        suff *= nums[n - 1 - i];
        max_prod = std::max({max_prod, pref, suff});
    }
    return max_prod;
}

