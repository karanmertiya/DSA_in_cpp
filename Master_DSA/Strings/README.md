# Strings
## 🧠 Core Intuition
Strings are fundamentally character arrays. String problems heavily test your knowledge of ASCII math, pointer manipulation, and string matching algorithms.

## 🛠️ Dependencies & Prerequisites
String mutability is the biggest language difference here. C++ strings are mutable. Python strings are IMMUTABLE.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <string>
#include <algorithm>

int main() {
    std::string s = "hello";
    
    // Accessing & Mutability (O(1))
    char first_char = s[0];
    s[0] = 'H'; // "Hello"
    
    // Iteration
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
    }
    
    // Substrings
    std::string sub = s.substr(1, 3); // (start_idx, length) -> "ell"
    
    // ASCII Math
    char c = 'c';
    int index = c - 'a'; // 2 (0-based index for alphabet)
    
    // Concatenation
    s += " world"; // O(N)
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
s = "hello"

# Accessing
first_char = s[0]

# Immutability! You cannot do s[0] = 'H'
# Convert to list if you need frequent mutations:
char_list = list(s)
char_list[0] = 'H'
s = "".join(char_list) # "Hello"

# Iteration
for i, char in enumerate(s):
    pass

# Substrings (Slicing)
sub = s[1:4] # (start_idx, end_idx_exclusive) -> "ell"

# ASCII Math
c = 'c'
index = ord(c) - ord('a') # 2
character = chr(97) # 'a'

# String building (Optimal)
# Using += in a loop is O(N^2) in Python! Use a list and .join()
builder = []
builder.append("world")
result = "".join(builder)
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Algorithm | Time Complexity |
| :--- | :--- | :--- |
| **Substring Search** | Brute Force | `O(N * M)` |
| **Substring Search** | KMP Algorithm | `O(N + M)` |
| **Substring Search** | Rabin-Karp | `O(N + M)` |

## 💡 Elite Patterns
- **Two Pointers:** Place pointers at both ends of the string to efficiently check for Palindromes or Reverse the string.
- **ASCII Array Hashing:** Instead of an expensive Hash Map, use a fixed `int[256]` or `int[26]` array for character frequencies to achieve `O(1)` space constraint.
- **KMP (Knuth-Morris-Pratt):** Builds a Longest Prefix Suffix (LPS) array to avoid redundant re-evaluations during substring matching.
