// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Binary search the max subarray sum `[max(nums), sum(nums)]`. For a `mid`, greedily split array. If subarrays needed `<= k`, `mid` is possible, search lower. Else search higher.

int splitArray(vector<int>& nums, int k) {
    int low = 0, high = 0;
    for(int n : nums) {
        low = max(low, n);
        high += n;
    }
    while(low < high) {
        int mid = low + (high - low) / 2;
        int pieces = 1, currentSum = 0;
        for(int n : nums) {
            if(currentSum + n > mid) {
                currentSum = n;
                pieces++;
            } else {
                currentSum += n;
            }
        }
        if(pieces <= k) high = mid;
        else low = mid + 1;
    }
    return low;
}

