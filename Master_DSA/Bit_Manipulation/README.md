# Bit Manipulation
## 🧠 Core Intuition
Operating directly on hardware-level binary integers provides hyper-optimized spatial and time complexities. Many integer array problems requiring `O(N)` space can be solved in `O(1)` space using XOR logic.

## 🛠️ Dependencies & Prerequisites
You only need the built-in bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`).

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <bitset>    // For printing binary representations
#include <iostream>

int main() {
    int x = 5; // 101
    int y = 3; // 011
    
    // Core Logic
    int and_val = x & y; // 001 (1)
    int or_val = x | y;  // 111 (7)
    int xor_val = x ^ y; // 110 (6)
    
    // Setting / Unsetting Bits (0-indexed from right)
    int i = 1;
    int set_bit = x | (1 << i);       // sets the ith bit to 1
    int unset_bit = x & ~(1 << i);    // sets the ith bit to 0
    int toggle_bit = x ^ (1 << i);    // flips the ith bit
    bool check_bit = x & (1 << i);    // checks if ith bit is 1
    
    // Built-in functions for counting bits (GCC specific)
    int set_bits = __builtin_popcount(x); // count 1s
    int leading_zeroes = __builtin_clz(x);
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
x, y = 5, 3

# Core Logic
and_val = x & y
or_val = x | y
xor_val = x ^ y

# Setting / Unsetting Bits (0-indexed from right)
i = 1
set_bit = x | (1 << i)       # sets the ith bit to 1
unset_bit = x & ~(1 << i)    # sets the ith bit to 0
toggle_bit = x ^ (1 << i)    # flips the ith bit
check_bit = (x & (1 << i)) != 0 # checks if ith bit is 1

# Useful Python bit functions
binary_string = bin(x) # '0b101'
set_bits = x.bit_count() # Python 3.10+
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Time Complexity | Bitwise Logic |
| :--- | :--- | :--- |
| **Check Odd/Even** | `O(1)` | `(n & 1) == 1` |
| **Check Power of 2** | `O(1)` | `(n & (n - 1)) == 0` |
| **Multiply by 2** | `O(1)` | `n << 1` |
| **Divide by 2** | `O(1)` | `n >> 1` |
| **XOR itself** | `O(1)` | `n ^ n = 0` |
| **XOR zero** | `O(1)` | `n ^ 0 = n` |

## 💡 Elite Patterns
- **XOR Magic:** Used extensively in "find the single missing element" problems since pairs cancel out to 0.
- **Brian Kernighan's Algorithm:** Used to count set bits efficiently. `n = n & (n - 1)` drops the lowest set bit.
- **Bitmasking:** Representing a subset of items as an integer `(0 to 2^N - 1)`. Extremely useful in DP + Bitmask problems.
