# Sorting Algorithms
## 🧠 Core Intuition
Sorting sequences is a prerequisite for many optimal algorithms (like Binary Search or Two Pointers). Understanding the internal mechanics of sorting (Divide & Conquer) is heavily tested.

## 🛠️ Dependencies & Prerequisites
You must know how to invoke your language's built-in sort and how to provide a custom comparator.

<details><summary><b>C++ Custom Sorting</b></summary>

```cpp
#include <vector>
#include <algorithm>

// Custom Comparator: Return true if 'a' should come BEFORE 'b'
bool compare(int a, int b) {
    return a > b; // Descending order
}

int main() {
    std::vector<int> arr = {1, 5, 2};
    
    // Sort descending using function
    std::sort(arr.begin(), arr.end(), compare);
    
    // Sort using Lambda (Modern C++)
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;
    });
}
```
</details>

<details><summary><b>Python Custom Sorting</b></summary>

```python
arr = [[1, 5], [2, 3], [1, 2]]

# Python uses 'key' functions instead of comparators
# Sort by 0th element ascending, then 1st element DESCENDING
arr.sort(key=lambda x: (x[0], -x[1]))

# If you strictly need a C++ style comparator, use cmp_to_key
from functools import cmp_to_key
def compare(a, b):
    if a < b: return -1 # a comes before b
    elif a > b: return 1 # b comes before a
    return 0
arr.sort(key=cmp_to_key(compare))
```
</details>

## ⏱️ Complexity Cheatsheet
| Algorithm | Best Time | Worst Time | Space | Stable? |
| :--- | :--- | :--- | :--- | :--- |
| **Merge Sort** | `O(N log N)` | `O(N log N)` | `O(N)` | Yes |
| **Quick Sort** | `O(N log N)` | `O(N^2)` | `O(log N)` | No |
| **Insertion Sort** | `O(N)` | `O(N^2)` | `O(1)` | Yes |
| **Heap Sort** | `O(N log N)` | `O(N log N)` | `O(1)` | No |

## 💡 Elite Patterns
- **Merge Sort for Inversions:** The process of merging two sorted halves directly exposes how many smaller elements appear on the right side of larger elements.
- **Quick Select:** An `O(N)` average-case algorithm derived from Quick Sort's partitioning to find the Kth largest/smallest element.
