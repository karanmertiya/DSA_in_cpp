// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Extended Boyer-Moore Voting Algorithm. There can be at most 2 elements appearing more than n/3 times. Maintain two candidate elements and their counts.

vector<int> majorityElement(vector<int>& nums) {
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    for(int el : nums) {
        if(el == num1) c1++;
        else if(el == num2) c2++;
        else if(c1 == 0) { num1 = el; c1 = 1; }
        else if(c2 == 0) { num2 = el; c2 = 1; }
        else { c1--; c2--; }
    }
    c1 = 0; c2 = 0;
    for(int el : nums) {
        if(el == num1) c1++;
        else if(el == num2) c2++;
    }
    vector<int> ans;
    if(c1 > nums.size() / 3) ans.push_back(num1);
    if(c2 > nums.size() / 3) ans.push_back(num2);
    return ans;
}

