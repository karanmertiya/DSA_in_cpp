// Time Complexity: O(N^2)
// Space Complexity: O(1) excluding output
// Explanation: Sort the array. Fix the first element `nums[i]`. Use two pointers (`left = i+1`, `right = n-1`) to find the remaining two elements that sum to `-nums[i]`. Skip duplicates for `i`, `left`, and `right` to ensure unique triplets.

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n - 2; i++) {
        if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            int low = i + 1, high = n - 1, sum = 0 - nums[i];
            while(low < high) {
                if(nums[low] + nums[high] == sum) {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    low++; high--;
                } else if(nums[low] + nums[high] < sum) low++;
                else high--;
            }
        }
    }
    return ans;
}

