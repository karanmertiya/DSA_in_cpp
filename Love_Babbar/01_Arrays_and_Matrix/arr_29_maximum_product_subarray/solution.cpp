// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int maxProduct(vector<int>& nums) {
    double pref = 1, suff = 1, ans = INT_MIN;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= nums[i];
        suff *= nums[n-i-1];
        ans = max({ans, pref, suff});
    }
    return (int)ans;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Maintain prefix and suffix products. If a 0 is encountered, reset the product to 1. The max overall is the answer since negatives cancel out in pairs.

int maxProduct(vector<int>& nums) {
    double pref = 1, suff = 1, ans = INT_MIN;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= nums[i];
        suff *= nums[n-i-1];
        ans = max({ans, pref, suff});
    }
    return (int)ans;
}

