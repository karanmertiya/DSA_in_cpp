# Hashing & Frequency Maps
## Core Concept
Utilizing `O(N)` auxiliary space to map keys to values, drastically reducing nested loop `O(N^2)` lookup times into optimal `O(1)` time. Crucial for advanced Prefix-Sum sub-array calculations.
## Syntax & Initialization
**C++:** 
```cpp
#include <unordered_map>
#include <unordered_set>
std::unordered_map<int, int> freq;
```
**Python:** 
```python
freq = {} # Dictionary
seen = set() # Hash Set
```
## Main Operations
- Insert/Lookup (Average): `O(1)` Time
- Insert/Lookup (Worst Case Collision): `O(N)` Time
- Prefix Sum Range Lookups: `O(1)` Time via Map.
