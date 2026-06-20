# Loop & Matrix Patterns
## 🧠 Core Intuition
Before diving into standard algorithms, mastering basic nested loops is absolutely mandatory. This section focuses purely on logic building via spatial printing patterns (Stars, Numbers, Alphabets).

## 🛠️ Dependencies & Prerequisites
No advanced libraries needed. You just need to understand basic console printing, newlines, and variable bounds.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <iostream>
using namespace std;

int main() {
    // Print without newline
    cout << "* ";
    
    // Print with newline
    cout << endl;
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
# Print without newline (Crucial for patterns!)
print("* ", end="")

# Print with newline
print()

# String multiplication (Python specific trick!)
print("* " * 5) # Prints "* * * * * "
```
</details>

## ⏱️ Complexity Cheatsheet
| Pattern Structure | Nested Depth | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| **Standard Grid** | 2 (Row, Col) | `O(N^2)` | `O(1)` |
| **Mirror Matrix** | 2 to 3 | `O(N^2)` | `O(1)` |

## 💡 Elite Tips
- **The Outer Loop always governs the Rows.** If `N=5`, your outer loop runs 5 times.
- **The Inner Loop always governs the Columns.** Connect the bounds of the inner loop directly to the row index `i`.
- Always search for algebraic symmetry. For pyramid patterns, space logic is usually `N - i` and character logic is `2 * i - 1`.
