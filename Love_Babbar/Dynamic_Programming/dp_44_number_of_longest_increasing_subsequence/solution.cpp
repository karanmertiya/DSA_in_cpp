// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Maintain `lengths[i]` (length of LIS ending at i) and `counts[i]` (number of LIS ending at i). If `nums[i] > nums[j]`: if `lengths[j] + 1 > lengths[i]`, then `lengths[i] = lengths[j] + 1` and `counts[i] = counts[j]`. Else if `lengths[j] + 1 == lengths[i]`, then `counts[i] += counts[j]`.

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), max_len = 0, res = 0;
    vector<int> len(n, 1), count(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                if(len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                } else if(len[j] + 1 == len[i]) {
                    count[i] += count[j];
                }
            }
        }
        if(len[i] > max_len) {
            max_len = len[i];
            res = count[i];
        } else if(len[i] == max_len) {
            res += count[i];
        }
    }
    return res;
}

