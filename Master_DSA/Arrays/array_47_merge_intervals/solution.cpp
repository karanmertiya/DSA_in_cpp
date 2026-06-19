// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Sort the intervals based on the starting time. Create a result list and add the first interval. For subsequent intervals, if the current interval's start time is <= the last merged interval's end time, update the end time of the last merged interval to `max(last.end, current.end)`. Else, add the current interval to the result list.

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] <= res.back()[1]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

