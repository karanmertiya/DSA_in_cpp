// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Maintain an array `tails` where `tails[i]` stores the smallest tail of all increasing subsequences of length `i+1`. Use binary search (`lower_bound`) to find the position to replace or append.

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for(int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if(it == tails.end()) tails.push_back(num);
        else *it = num;
    }
    return tails.size();
}

