// Time Complexity: O(N)
// Space Complexity: O(1) (at most 3 elements in map)
// Explanation: This translates to finding the longest subarray with at most 2 distinct elements. Maintain a frequency map and use a sliding window. If distinct elements > 2, shrink the window until distinct elements <= 2.

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> count;
    int l = 0, maxFruits = 0;
    for(int r = 0; r < fruits.size(); r++) {
        count[fruits[r]]++;
        while(count.size() > 2) {
            count[fruits[l]]--;
            if(count[fruits[l]] == 0) count.erase(fruits[l]);
            l++;
        }
        maxFruits = max(maxFruits, r - l + 1);
    }
    return maxFruits;
}

