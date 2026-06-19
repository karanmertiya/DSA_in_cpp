// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain the prefix product and suffix product. If a zero is encountered, reset the product to 1. The maximum product will be the maximum of all prefix and suffix products.

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    double pre = 1, suff = 1;
    double ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max({ans, pre, suff});
    }
    return (int)ans;
}

