// Time Complexity: O(N log N) (Trade-off)
// Space Complexity: O(1)
// Explanation: Sort the array and return the last element.

#include <vector>
#include <algorithm>

int largestElementBrute(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    return arr.back();
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1)
// Explanation: Maintain a max variable and linearly scan the array updating it.

#include <vector>

int largestElementOptimal(std::vector<int>& arr) {
    int max_val = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

