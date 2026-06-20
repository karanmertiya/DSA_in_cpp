# Binary Search
## 🧠 Core Intuition
A divide and conquer algorithm used strictly on **monotonic** (sorted/predictable) search spaces. If you can eliminate half of the search space based on a condition, you can reduce `O(N)` linear searches to `O(log N)`.

## 🛠️ Dependencies & Prerequisites
Avoid integer overflow when calculating `mid`. Know how to use built-in lower/upper bound functions.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <algorithm> // For bounds
#include <vector>

int main() {
    int low = 0, high = 1000000;
    // ALWAYS use this to prevent (low + high) overflow
    int mid = low + (high - low) / 2; 
    
    std::vector<int> arr = {1, 2, 4, 4, 5};
    
    // Lower Bound: First element >= target
    auto lb = std::lower_bound(arr.begin(), arr.end(), 4);
    int lb_idx = lb - arr.begin(); // index 2
    
    // Upper Bound: First element > target
    auto ub = std::upper_bound(arr.begin(), arr.end(), 4);
    int ub_idx = ub - arr.begin(); // index 4
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
import bisect

low, high = 0, 1000000
# Python handles large ints, so (low + high) // 2 is totally safe!
mid = (low + high) // 2

arr = [1, 2, 4, 4, 5]

# Lower Bound (bisect_left): First element >= target
lb_idx = bisect.bisect_left(arr, 4) # index 2

# Upper Bound (bisect_right): First element > target
ub_idx = bisect.bisect_right(arr, 4) # index 4
```
</details>

## ⏱️ Complexity Cheatsheet
| Problem Space | Range Size | Time Complexity | Space |
| :--- | :--- | :--- | :--- |
| **Sorted Arrays** | `N` elements | `O(log N)` | `O(1)` |
| **Answer Range** | `Max - Min` | `O(log(Max - Min))` | `O(1)` |

## 💡 Elite Patterns
- **Search on Answers:** Instead of searching an array, search a numerical range (e.g., `low = 1`, `high = max(array)`). Use an `isValid(mid)` helper function. (Classic for Allocation/Min-Max problems).
- **Lower/Upper Bound:** Used extensively. Lower Bound returns the first index `>= target`. Upper bound returns the first index `> target`.
- **Rotated Sorted Arrays:** Identify which half of the array is properly sorted. If the target falls within that sorted range, search there. Otherwise, search the other half.
