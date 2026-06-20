// Time Complexity: O(N log N)
// Space Complexity: O(1) or O(N) depending on sort
// Explanation: Brute Force: Sort the array and return the last element.

#include <vector>
#include <algorithm>

int largest(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    return arr.back();
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Iterate through the array maintaining a variable for the maximum element seen so far.

#include <vector>
#include <algorithm>

int largest(std::vector<int> &arr) {
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

