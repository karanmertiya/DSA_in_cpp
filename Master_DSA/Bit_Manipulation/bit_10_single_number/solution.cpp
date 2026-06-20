// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a Hash Map to count occurrences. Return the element with count 1.

int singleNumberHash(vector<int>& nums) {
    unordered_map<int, int> counts;
    for(int num : nums) counts[num]++;
    for(auto it : counts) {
        if(it.second == 1) return it.first;
    }
    return -1;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use XOR bitwise operation. `X ^ X = 0` and `X ^ 0 = X`. XORing all elements pairs up the duplicates to 0, leaving the single element.

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int num : nums) {
        ans ^= num;
    }
    return ans;
}

