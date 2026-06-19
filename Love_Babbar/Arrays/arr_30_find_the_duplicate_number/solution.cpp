// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Floyd's Tortoise and Hare (Cycle Detection). Treat the array values as pointers to the next index. Since there's a duplicate, a cycle must exist. Find the intersection point of slow and fast pointers, then find the entrance to the cycle.

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
    fast = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

