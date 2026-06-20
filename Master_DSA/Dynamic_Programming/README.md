# Dynamic Programming
## 🧠 Core Intuition
Those who cannot remember the past are condemned to repeat it. DP optimizes overlapping subproblems by caching answers (Memoization) or pre-computing them bottom-up (Tabulation).

## 🛠️ Dependencies & Prerequisites
You must know how to initialize 1D and 2D arrays (tables) filled with default values (like -1 or Infinity).

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <vector>
using namespace std;

int main() {
    int N = 10, M = 5;
    
    // 1D DP Array initialized to -1
    vector<int> dp1(N, -1);
    
    // 2D DP Array initialized to 0
    vector<vector<int>> dp2(N, vector<int>(M, 0));
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
N, M = 10, 5

# 1D DP Array
dp1 = [-1] * N

# 2D DP Array (NEVER do [[0]*M]*N, it copies references!)
dp2 = [[0 for _ in range(M)] for _ in range(N)]

# Python cheat code: @cache for instant memoization!
from functools import cache

@cache
def solve(i, j):
    if i == 0: return 1
    return solve(i-1, j) + solve(i, j-1)
```
</details>

## ⏱️ Complexity Cheatsheet
| Problem Class | Typical Time | Typical Space | Space Optimized |
| :--- | :--- | :--- | :--- |
| **1D Array (Stairs)** | `O(N)` | `O(N)` | `O(1)` |
| **2D Grid (Paths)** | `O(N * M)` | `O(N * M)` | `O(M)` |
| **String Subsequence**| `O(N * M)` | `O(N * M)` | `O(M)` |
| **Matrix Chain / Partition**| `O(N^3)` | `O(N^2)` | N/A |

## 💡 Elite Patterns
- **0/1 Knapsack:** A 2D DP structure where state relies on `dp[index][remaining_capacity]`.
- **Longest Common Subsequence (LCS):** Compare characters. If match, `1 + dp[i-1][j-1]`. If not, `max(dp[i-1][j], dp[i][j-1])`.
- **Space Optimization:** In 2D DP, if the current row `i` only relies on the previous row `i-1`, you can reduce an `O(N*M)` matrix to two `O(M)` 1D arrays.
