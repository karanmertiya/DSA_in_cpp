// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Maintain two lengths: `up` (ending with ascending) and `down` (ending with descending). Iterate array: if `arr[i] > arr[i-1]`, `up = down + 1`. If `arr[i] < arr[i-1]`, `down = up + 1`. Return `max(up, down)`.

int AlternatingaMaxLength(vector<int>& nums) {
    if(nums.empty()) return 0;
    int up = 1, down = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i-1]) up = down + 1;
        else if(nums[i] < nums[i-1]) down = up + 1;
    }
    return max(up, down);
}

