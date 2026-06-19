// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use Floyd's Tortoise and Hare algorithm. Initialize `slow = nums[0]` and `fast = nums[0]`. Move `slow` by 1 step (`nums[slow]`) and `fast` by 2 steps (`nums[nums[fast]]`). They will meet in a cycle. Then, reset `slow` to `nums[0]` and move both by 1 step until they meet. The meeting point is the duplicate.

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
    slow = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

