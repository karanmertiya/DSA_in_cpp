# Arrays

## Core Concept
A contiguous block of memory utilized to store linear data linearly. Crucial for understanding random access, contiguous traversal, and sub-array algorithms like Kadane's.

## Syntax & Initialization
**C++:** 
```cpp
#include <vector>
std::vector<int> arr(10, 0); // Size 10 initialized to 0
```
**Python:** 
```python
arr = [0] * 10 # Size 10 initialized to 0
```

## Main Operations
- Random Access: `O(1)` Time
- Insertion / Deletion at End: `O(1)` Amortized Time
- Insertion / Deletion at Middle: `O(N)` Time (Shift required)
- Traversal: `O(N)` Time
