// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Compute LIS ending at `i` from left to right (`inc[i]`). Compute LIS starting at `i` from right to left (`dec[i]`). The max bitonic subsequence length is `max(inc[i] + dec[i] - 1)` for all `i`. Sometimes pure increasing or pure decreasing is also bitonic depending on definition, adjust if necessary.

int LongestBitonicSequence(vector<int> nums) {
    int n = nums.size();
    vector<int> inc(n, 1), dec(n, 1);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) inc[i] = max(inc[i], inc[j] + 1);
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(nums[i] > nums[j]) dec[i] = max(dec[i], dec[j] + 1);
        }
    }
    int max_len = 0;
    for(int i = 0; i < n; i++) {
        // Depending on problem variant, might require both to be > 1 to be valid peak
        max_len = max(max_len, inc[i] + dec[i] - 1);
    }
    return max_len;
}

