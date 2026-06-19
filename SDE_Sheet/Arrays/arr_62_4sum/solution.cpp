// Time Complexity: O(N^3)
// Space Complexity: O(1) excluding output
// Explanation: Sort the array. Fix the first two elements using nested loops (`i` and `j`). Then use two pointers (`left` and `right`) to find the remaining two elements that sum up to `target - nums[i] - nums[j]`. Skip duplicates for all 4 variables.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 && nums[j] == nums[j-1]) continue;
            int low = j + 1, high = n - 1;
            while(low < high) {
                long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];
                if(sum == target) {
                    ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    low++; high--;
                } else if(sum < target) low++;
                else high--;
            }
        }
    }
    return ans;
}

