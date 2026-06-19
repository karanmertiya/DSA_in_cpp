// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterate from left to right calculating prefix product, and right to left calculating suffix product. If either is 0, reset it to 1. The max product will be the max of all prefix and suffix products.

long long maxProduct(vector<int> arr, int n) {
    long long max_prod = INT_MIN;
    long long pref = 1, suff = 1;
    for(int i = 0; i < n; i++) {
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= arr[i];
        suff *= arr[n - i - 1];
        max_prod = max({max_prod, pref, suff});
    }
    return max_prod;
}

