# Arrays
## 🧠 Core Intuition
The most foundational data structure. Arrays are contiguous memory blocks. The main challenge in array problems is reducing the time complexity from `O(N^2)` brute-force loops to `O(N)` single passes.

## 🛠️ Dependencies & Prerequisites
You must be completely fluent in dynamic arrays, index mapping, and multi-dimensional traversal.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <vector>
#include <algorithm> // for std::sort, std::reverse, std::max

int main() {
    // 1D Arrays
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int N = arr.size();
    
    // Accessing & Iterating (1D)
    for(int i = 0; i < N; i++) {
        int curr = arr[i];
    }
    
    // Range-based for loop (Read-Only)
    for(int val : arr) { /* do something */ }
    // Range-based for loop (Modifiable)
    for(int& val : arr) { val *= 2; }
    
    // 2D Arrays (Matrix)
    int rows = 3, cols = 4;
    std::vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    
    // Accessing & Iterating (2D)
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            int cell = matrix[r][c];
        }
    }
    
    // Useful Methods
    arr.push_back(6); // O(1)
    arr.pop_back();   // O(1)
    std::sort(arr.begin(), arr.end());
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
# 1D Arrays
arr = [1, 2, 3, 4, 5]
N = len(arr)

# Accessing & Iterating (1D)
for i in range(N):
    curr = arr[i]

# Enumerate (Index and Value simultaneously)
for i, val in enumerate(arr):
    print(f"Index {i} has value {val}")

# 2D Arrays (Matrix)
rows, cols = 3, 4
# CORRECT 2D initialization (DO NOT USE [[0]*cols]*rows)
matrix = [[0 for _ in range(cols)] for _ in range(rows)]

# Accessing & Iterating (2D)
for r in range(rows):
    for c in range(cols):
        cell = matrix[r][c]

# Slicing (Deep copying subsets)
copy_arr = arr[:]
first_half = arr[:N//2]
reversed_arr = arr[::-1]
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Access `A[i]`** | `O(1)` | `O(1)` |
| **Search (Unsorted)** | `O(N)` | `O(1)` |
| **Insert/Delete (End)** | `O(1)` | `O(1)` |
| **Insert/Delete (Middle)** | `O(N)` | `O(1)` |

## 💡 Elite Patterns
- **Kadane's Algorithm:** Optimal `O(N)` dynamic programming approach for Maximum Subarray Sum.
- **Dutch National Flag (DNF):** Three pointers (low, mid, high) used to sort arrays of 3 unique elements (like 0s, 1s, and 2s) in a single pass.
- **Prefix Sum:** Precompute cumulative sums to answer range query sums in `O(1)` time.
- **Boyer-Moore Majority Vote:** Find the majority element (`> N/2` occurrences) in `O(N)` time and `O(1)` space.
