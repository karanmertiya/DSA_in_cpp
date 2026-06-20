// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int countPairs(vector<int>& nums, int mid) {
    int count = 0, l = 0;
    for(int r = 0; r < nums.size(); r++) {
        while(nums[r] - nums[l] > mid) l++;
        count += (r - l);
    }
    return count;
}
int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.back() - nums.front();
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(countPairs(nums, mid) >= k) high = mid;
        else low = mid + 1;
    }
    return low;
}

// Time Complexity: O(N log N + N log(max_dist))
// Space Complexity: O(1)
// Explanation: Optimal: Sort array. Binary search on distance `[0, nums.back() - nums.front()]`. For a candidate `mid`, count pairs with distance `<= mid` using a sliding window. If count >= k, search left. Else search right.

int countPairs(vector<int>& nums, int mid) {
    int count = 0, l = 0;
    for(int r = 0; r < nums.size(); r++) {
        while(nums[r] - nums[l] > mid) l++;
        count += (r - l);
    }
    return count;
}
int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int low = 0, high = nums.back() - nums.front();
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(countPairs(nums, mid) >= k) high = mid;
        else low = mid + 1;
    }
    return low;
}

