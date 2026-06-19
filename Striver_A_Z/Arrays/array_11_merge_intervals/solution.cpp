// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Sort the intervals based on the starting time. Then iterate and merge if the current interval's start is <= the last merged interval's end.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); ++i) {
        if(merged.back()[1] >= intervals[i][0]) {
            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

