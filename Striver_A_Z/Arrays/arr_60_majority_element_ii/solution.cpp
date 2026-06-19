// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Since at most two elements can appear more than n/3 times, maintain two potential candidates (`num1`, `num2`) and their counts. Iterate through the array updating candidates and counts. After finding the candidates, iterate again to count their actual occurrences and check if they exceed n/3.

vector<int> majorityElement(vector<int>& nums) {
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    for(int x : nums) {
        if(x == num1) c1++;
        else if(x == num2) c2++;
        else if(c1 == 0) { num1 = x; c1 = 1; }
        else if(c2 == 0) { num2 = x; c2 = 1; }
        else { c1--; c2--; }
    }
    vector<int> ans;
    c1 = 0; c2 = 0;
    for(int x : nums) {
        if(x == num1) c1++;
        else if(x == num2) c2++;
    }
    if(c1 > nums.size() / 3) ans.push_back(num1);
    if(c2 > nums.size() / 3) ans.push_back(num2);
    return ans;
}

