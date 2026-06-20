// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Maintain two variables, `largest` and `second_largest`. Update them simultaneously during a single pass.

#include <vector>

int print2largest(std::vector<int> &arr) {
    int largest = -1, second_largest = -1;
    for (int num : arr) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        } else if (num > second_largest && num != largest) {
            second_largest = num;
        }
    }
    return second_largest;
}

