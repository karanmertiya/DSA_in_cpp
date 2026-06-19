// Time Complexity: O(N + M)
// Space Complexity: O(N)
// Explanation: Monotonic Stack traversing `nums2` from right to left. Maintain stack of elements in decreasing order.

#include <vector>
#include <stack>
#include <unordered_map>
std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> mpp;
    std::stack<int> st;
    for(int i = nums2.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums2[i]) st.pop();
        if(st.empty()) mpp[nums2[i]] = -1;
        else mpp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    std::vector<int> ans;
    for(int num : nums1) ans.push_back(mpp[num]);
    return ans;
}

