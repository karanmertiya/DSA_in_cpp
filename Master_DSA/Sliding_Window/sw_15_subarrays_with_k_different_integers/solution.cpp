// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Like "Binary Subarrays With Sum", the number of subarrays with exactly k distinct integers is `atMost(k) - atMost(k-1)`. The `atMost` function uses a sliding window with a hash map to track the frequencies of elements.

int atMost(vector<int>& nums, int k) {
    if(k == 0) return 0;
    unordered_map<int, int> count;
    int left = 0, res = 0;
    for(int right = 0; right < nums.size(); right++) {
        count[nums[right]]++;
        while(count.size() > k) {
            count[nums[left]]--;
            if(count[nums[left]] == 0) count.erase(nums[left]);
            left++;
        }
        res += (right - left + 1);
    }
    return res;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

