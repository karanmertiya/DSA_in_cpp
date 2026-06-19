// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Sort the intervals based on the starting times. Iterate through the intervals, if the current interval overlaps with the last merged interval, update the end time of the last merged interval.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for(auto interval : intervals) {
        if(merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

