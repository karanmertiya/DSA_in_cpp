// Time Complexity: O(N log N) (Trade-off)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use an auxiliary HashSet to store unique elements, then put them back.

#include <vector>
#include <set>

int removeDuplicatesBrute(std::vector<int>& arr) {
    std::set<int> unique_set(arr.begin(), arr.end());
    int i = 0;
    for (int it : unique_set) {
        arr[i++] = it;
    }
    return unique_set.size();
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Two-pointer approach: Place unique elements at the `i` pointer while `j` scans.

#include <vector>

int removeDuplicatesOptimal(std::vector<int>& arr) {
    if (arr.empty()) return 0;
    int i = 0;
    for (int j = 1; j < arr.size(); j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

