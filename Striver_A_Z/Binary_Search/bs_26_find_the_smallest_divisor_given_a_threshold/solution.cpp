// Time Complexity: O(N log(Max))
// Space Complexity: O(1)
// Explanation: Binary search for divisor from `1` to `max(nums)`. For a divisor `mid`, sum `ceil(num / mid)`. If sum <= threshold, move `high = mid - 1`, else `low = mid + 1`.

int sumByD(vector<int>& nums, int d) {
    int sum = 0;
    for(int num : nums) {
        sum += ceil((double)num / (double)d);
    }
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(sumByD(nums, mid) <= threshold) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

