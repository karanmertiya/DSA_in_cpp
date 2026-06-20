// Time Complexity: O(N log(max(nums)))
// Space Complexity: O(1)
// Explanation: Optimal: Binary search the divisor from 1 to `max(nums)`. Compute `sum(ceil(num / mid))`. If sum <= threshold, shrink high.

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while(low <= high) {
        int mid = low + (high - low) / 2;
        long long sum = 0;
        for(int num : nums) sum += ceil((double)num / mid);
        if(sum <= threshold) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

