// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Maintain an array `temp` storing the smallest tail of all increasing subsequences of length i+1 in `temp[i]`. For each num, use binary search to find its position in `temp`. If num is larger than all, append it. Otherwise, replace the element.

int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    for(int num : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), num);
        if(it == temp.end()) temp.push_back(num);
        else *it = num;
    }
    return temp.size();
}

