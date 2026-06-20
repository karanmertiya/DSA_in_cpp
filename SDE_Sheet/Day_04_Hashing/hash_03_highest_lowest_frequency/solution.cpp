// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Optimal: Build a frequency map, then iterate through the map to find the max and min frequencies.

#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

void findHighLowFreq(std::vector<int>& arr) {
    std::unordered_map<int, int> freq;
    for(int num : arr) freq[num]++;
    
    int max_f = 0, min_f = INT_MAX;
    int max_ele = 0, min_ele = 0;
    
    for(auto it : freq) {
        if(it.second > max_f) { max_f = it.second; max_ele = it.first; }
        if(it.second < min_f) { min_f = it.second; min_ele = it.first; }
    }
}

