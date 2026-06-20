# Recursion & Backtracking
## 🧠 Core Intuition
Recursion breaks large problems into identical, smaller subproblems. Backtracking extends this by exploring all potential paths and "undoing" choices when a path hits a dead end.

## 🛠️ Dependencies & Prerequisites
You must understand Stack frames, pass-by-reference vs pass-by-value, and recursion limits.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <vector>
using namespace std;

// Pass path by reference to save memory, pass answer by reference to accumulate
void backtrack(int index, vector<int>& path, vector<vector<int>>& ans) {
    if (index == 5) { // Base Case
        ans.push_back(path);
        return;
    }
    
    // Choose
    path.push_back(index);
    // Explore
    backtrack(index + 1, path, ans);
    // Un-choose (Backtrack!)
    path.pop_back();
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
import sys
# Python's default recursion limit is 1000. Increase it for deep graphs/trees.
sys.setrecursionlimit(20000)

def backtrack(index, path, ans):
    if index == 5: # Base Case
        ans.append(path[:]) # MUST slice [:] to copy! Otherwise references mutate.
        return
        
    # Choose
    path.append(index)
    # Explore
    backtrack(index + 1, path, ans)
    # Un-choose (Backtrack!)
    path.pop()
```
</details>

## ⏱️ Complexity Cheatsheet
| Algorithm | Time Complexity | Space (Call Stack) |
| :--- | :--- | :--- |
| **Subsets (Pick/Don't Pick)** | `O(2^N)` | `O(N)` |
| **Permutations** | `O(N!)` | `O(N)` |
| **N-Queens** | `O(N!)` | `O(N)` |

## 💡 Elite Patterns
- **Pick / Non-Pick Logic:** At every element in an array, you have two choices: include it in your subset or ignore it.
- **Backtracking State Reversal:** Remember to `.pop()` or un-mark the state after the recursive call returns, so sibling branches start with a clean slate.
- **Pruning:** Sort the array first to easily skip duplicate elements during recursion to avoid duplicate subsets/permutations.
