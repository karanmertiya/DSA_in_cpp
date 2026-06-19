// Time Complexity: O(N log N * M)
// Space Complexity: O(1) auxiliary
// Explanation: Sort the array of strings. Compare only the first and last strings in the sorted array, as they will have the most differing characters.

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string first = strs[0], last = strs.back();
    int i = 0;
    while(i < first.size() && first[i] == last[i]) i++;
    return first.substr(0, i);
}

