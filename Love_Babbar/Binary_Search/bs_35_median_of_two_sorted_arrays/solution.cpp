// Time Complexity: O(log(min(N, M)))
// Space Complexity: O(1)
// Explanation: Ensure `nums1` is the smaller array. Partition both arrays such that the left half has `(n+m+1)/2` elements. Use binary search on `nums1` to find the correct partition where `max(left1) <= min(right2)` and `max(left2) <= min(right1)`. The median depends on whether total elements is odd or even.

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int n = nums1.size(), m = nums2.size();
    int low = 0, high = n;
    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;
        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
        int right1 = cut1 == n ? INT_MAX : nums1[cut1];
        int right2 = cut2 == m ? INT_MAX : nums2[cut2];
        if(left1 <= right2 && left2 <= right1) {
            if((n + m) % 2 == 0) return (max(left1, left2) + min(right1, right2)) / 2.0;
            else return max(left1, left2);
        } else if(left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

