# Strings
## Core Concept
Essentially Arrays of Characters. Focus heavily shifts towards ASCII math mapping (`char - 'a'`) and Substring traversal logic like expanding around centers for Palindromes.
## Syntax & Initialization
**C++:** (Mutable String)
```cpp
#include <string>
std::string s = "hello";
s[0] = 'y'; // Valid
```
**Python:** (Immutable String)
```python
s = "hello"
# s[0] = 'y' # Invalid!
s = "y" + s[1:]
```
## Main Operations
- Substring Generation: `O(N)` Space/Time
- Reversing: `O(N)` Time
