// Time Complexity: O(N log N * M)
// Space Complexity: O(1)
// Explanation: Sort the array of strings. Compare the first and the last string in the sorted array, as they will be the most different. The common prefix of these two will be the common prefix for all.

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string first = strs[0], last = strs[strs.size() - 1];
    int i = 0;
    while(i < first.length() && first[i] == last[i]) i++;
    return first.substr(0, i);
}

