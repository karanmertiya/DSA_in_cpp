// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int countPartitions(vector<int>& a, int maxSum) {
    int n = a.size(), partitions = 1, subarraySum = 0;
    for(int i=0; i<n; i++) {
        if(subarraySum + a[i] <= maxSum) {
            subarraySum += a[i];
        } else {
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int partitions = countPartitions(nums, mid);
        if(partitions > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

// Time Complexity: O(N log(Sum-Max))
// Space Complexity: O(1)
// Explanation: Optimal: Identical logic to Allocate Books. Binary search from `max(nums)` to `sum(nums)`.

int countPartitions(vector<int>& a, int maxSum) {
    int n = a.size(), partitions = 1, subarraySum = 0;
    for(int i=0; i<n; i++) {
        if(subarraySum + a[i] <= maxSum) {
            subarraySum += a[i];
        } else {
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int partitions = countPartitions(nums, mid);
        if(partitions > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

