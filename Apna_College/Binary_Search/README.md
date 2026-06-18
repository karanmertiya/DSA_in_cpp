# Binary Search
## Core Concept
A divide and conquer search algorithm utilized strictly on **sorted** spaces. Cuts the search space in half each iteration.
## Syntax & Initialization
Maintain `low` and `high` pointers. Calculate `mid = low + (high - low) / 2` to prevent integer overflow.
## Main Operations
- Time Complexity: `O(log N)`
- Space Complexity: `O(1)`
