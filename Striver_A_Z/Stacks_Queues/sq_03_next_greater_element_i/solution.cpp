// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N)
// Explanation: Iterate backwards maintaining a strictly decreasing Monotonic Stack. The top of the stack is the next greater element.

#include <vector>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int>& nums) {
    std::vector<int> res(nums.size(), -1);
    std::stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(nums[i]);
    }
    return res;
}

