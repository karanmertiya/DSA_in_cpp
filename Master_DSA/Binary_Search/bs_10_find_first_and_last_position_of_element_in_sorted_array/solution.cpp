// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: Use Binary Search twice. Once to find the first occurrence (when nums[mid] == target, high = mid - 1 but record mid) and once to find the last occurrence (when nums[mid] == target, low = mid + 1 but record mid).

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            res[0] = mid;
            high = mid - 1;
        } else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            res[1] = mid;
            low = mid + 1;
        } else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return res;
}

