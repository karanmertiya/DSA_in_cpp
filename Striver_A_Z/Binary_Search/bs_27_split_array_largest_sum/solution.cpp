// Time Complexity: O(N log(sum - max))
// Space Complexity: O(1)
// Explanation: Search space is `[max(nums), sum(nums)]`. For a `mid` maximum sum, count the subarrays needed. If `count <= k`, `mid` is possible, search left. Else, search right. This is identical to the Painter's Partition or Book Allocation problem.

int countSubarrays(vector<int>& a, int maxSum) {
    int partitions = 1, currentSum = 0;
    for(int i = 0; i < a.size(); i++) {
        if(currentSum + a[i] <= maxSum) {
            currentSum += a[i];
        } else {
            partitions++;
            currentSum = a[i];
        }
    }
    return partitions;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = 0;
    for(int n : nums) high += n;
    while(low <= high) {
        int mid = (low + high) / 2;
        int partitions = countSubarrays(nums, mid);
        if(partitions > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

