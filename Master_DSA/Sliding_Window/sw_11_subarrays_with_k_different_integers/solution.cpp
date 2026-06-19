// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Finding exact `k` distinct is hard directly. Instead, find subarrays with at most `k` distinct integers. The number of exact `k` is `atMost(k) - atMost(k - 1)`. The `atMost` function uses a sliding window.

int atMost(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int res = 0, i = 0;
    for(int j = 0; j < nums.size(); j++) {
        if(count[nums[j]] == 0) k--;
        count[nums[j]]++;
        while(k < 0) {
            count[nums[i]]--;
            if(count[nums[i]] == 0) k++;
            i++;
        }
        res += j - i + 1;
    }
    return res;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

