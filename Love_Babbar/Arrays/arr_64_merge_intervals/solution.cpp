// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Sort the intervals by their start times. Iterate through them. If the result list is empty or the current interval's start is > the last interval's end, append it. Otherwise, update the last interval's end to the maximum of its end and current end.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
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

