// Time Complexity: O(N log N * M) (Trade-off)
// Space Complexity: O(1)
// Explanation: Sort the array of strings. The longest common prefix of the entire array must be the common prefix of the first and last strings in the sorted array.

#include <string>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if(strs.empty()) return "";
    std::sort(strs.begin(), strs.end());
    std::string first = strs[0];
    std::string last = strs.back();
    int i = 0;
    while(i < first.length() && i < last.length() && first[i] == last[i]) {
        i++;
    }
    return first.substr(0, i);
}

