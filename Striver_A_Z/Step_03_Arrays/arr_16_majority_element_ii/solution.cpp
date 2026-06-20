// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>

std::vector<int> majorityElement(std::vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    for(int num : nums) {
        if(cnt1 == 0 && num != el2) {
            cnt1 = 1; el1 = num;
        } else if(cnt2 == 0 && num != el1) {
            cnt2 = 1; el2 = num;
        } else if(num == el1) cnt1++;
        else if(num == el2) cnt2++;
        else {
            cnt1--; cnt2--;
        }
    }
    cnt1 = 0; cnt2 = 0;
    for(int num : nums) {
        if(num == el1) cnt1++;
        if(num == el2) cnt2++;
    }
    std::vector<int> ans;
    if(cnt1 > nums.size() / 3) ans.push_back(el1);
    if(cnt2 > nums.size() / 3) ans.push_back(el2);
    return ans;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Extended Moore's Voting Algorithm. At most TWO elements can appear > N/3 times. Track two candidates and two counters.

#include <vector>

std::vector<int> majorityElement(std::vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    for(int num : nums) {
        if(cnt1 == 0 && num != el2) {
            cnt1 = 1; el1 = num;
        } else if(cnt2 == 0 && num != el1) {
            cnt2 = 1; el2 = num;
        } else if(num == el1) cnt1++;
        else if(num == el2) cnt2++;
        else {
            cnt1--; cnt2--;
        }
    }
    cnt1 = 0; cnt2 = 0;
    for(int num : nums) {
        if(num == el1) cnt1++;
        if(num == el2) cnt2++;
    }
    std::vector<int> ans;
    if(cnt1 > nums.size() / 3) ans.push_back(el1);
    if(cnt2 > nums.size() / 3) ans.push_back(el2);
    return ans;
}

