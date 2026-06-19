// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Insert all elements into a hash set. Iterate through the set. If `x - 1` is not in the set, `x` is the start of a sequence. Count consecutive elements `x + 1`, `x + 2`... Update max length.

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;
    for(int num : s) {
        if(s.find(num - 1) == s.end()) {
            int currNum = num;
            int currLen = 1;
            while(s.find(currNum + 1) != s.end()) {
                currNum++;
                currLen++;
            }
            maxLen = max(maxLen, currLen);
        }
    }
    return maxLen;
}

