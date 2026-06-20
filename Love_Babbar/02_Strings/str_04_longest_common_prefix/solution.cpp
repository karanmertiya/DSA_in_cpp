// Time Complexity: O(N log N * M) (Constraint)
// Space Complexity: O(1) / O(M)
// Explanation: Sort the array. The common prefix will be constrained by the first and last strings in the sorted array.

#include <string>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    std::sort(strs.begin(), strs.end());
    std::string first = strs.front();
    std::string last = strs.back();
    int i = 0;
    while(i < first.size() && i < last.size() && first[i] == last[i]) {
        i++;
    }
    return first.substr(0, i);
}

