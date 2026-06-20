// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Brute Force: Sort the array, then iterate from the back to find the first element smaller than the largest.

int print2largest(int arr[], int n) {
    std::sort(arr, arr+n);
    for(int i=n-2; i>=0; i--) {
        if(arr[i] != arr[n-1]) return arr[i];
    }
    return -1;
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Optimal: Maintain two variables, `largest` and `second_largest`. Update them simultaneously during a single pass.

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

