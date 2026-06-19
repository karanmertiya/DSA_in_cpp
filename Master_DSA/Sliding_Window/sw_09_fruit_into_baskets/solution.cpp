// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: This translates to finding the longest subarray with at most 2 distinct elements. Use a hash map to keep track of fruit counts in the current window. Expand right, update map. If map size > 2, shrink from left until map size is 2.

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> count;
    int left = 0, maxLen = 0;
    for(int right = 0; right < fruits.size(); right++) {
        count[fruits[right]]++;
        while(count.size() > 2) {
            count[fruits[left]]--;
            if(count[fruits[left]] == 0) count.erase(fruits[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

