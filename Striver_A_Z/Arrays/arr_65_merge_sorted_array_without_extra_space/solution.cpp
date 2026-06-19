// Time Complexity: O(M + N)
// Space Complexity: O(1)
// Explanation: Since `nums1` has enough space at the end, use three pointers: `p1` at the end of valid elements in `nums1` (m-1), `p2` at the end of `nums2` (n-1), and `p` at the very end of `nums1` (m+n-1). Compare elements at `p1` and `p2`, put the larger one at `p`, and decrement pointers.

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1, p2 = n - 1, p = m + n - 1;
    while(p1 >= 0 && p2 >= 0) {
        if(nums1[p1] > nums2[p2]) nums1[p--] = nums1[p1--];
        else nums1[p--] = nums2[p2--];
    }
    while(p2 >= 0) nums1[p--] = nums2[p2--];
}

