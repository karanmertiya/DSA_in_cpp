# Stacks & Queues
## 🧠 Core Intuition
Sequential constraints. Stacks enforce Last-In-First-Out (LIFO) for reversing/matching. Queues enforce First-In-First-Out (FIFO) for scheduling and BFS.

## 🛠️ Dependencies & Prerequisites
You must know the language-specific standard libraries for Stacks, Queues, and Double-Ended Queues (Deques).

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <stack>
#include <queue>
#include <deque>

int main() {
    std::stack<int> s;
    s.push(1);
    int top = s.top(); // Get top element
    s.pop();           // Remove top element (void return)

    std::queue<int> q;
    q.push(1);
    int front = q.front(); // Get front element
    q.pop();

    std::deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.pop_back();
    dq.pop_front();
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
from collections import deque

# Stack (List acts as a perfect stack in Python)
stack = []
stack.append(1)    # Push
top = stack[-1]    # Top
stack.pop()        # Pop

# Queue & Deque (NEVER use list for queue, pop(0) is O(N))
# ALWAYS use collections.deque
q = deque()
q.append(1)        # Push back
front = q[0]       # Front
q.popleft()        # Pop front (O(1))

q.appendleft(2)    # Push front
```
</details>

## ⏱️ Complexity Cheatsheet
| Structure | Push Time | Pop Time | Top/Front Time |
| :--- | :--- | :--- | :--- |
| **Stack** | `O(1)` | `O(1)` | `O(1)` |
| **Queue** | `O(1)` | `O(1)` | `O(1)` |
| **Deque** | `O(1)` | `O(1)` | `O(1)` |

## 💡 Elite Patterns
- **Monotonic Stack:** Keep the stack elements strictly increasing or strictly decreasing. Essential for "Next Greater Element" and "Largest Rectangle in Histogram".
- **Balanced Parentheses:** Push opening brackets to the stack. When closing brackets appear, pop and check for matching types.
- **Min Stack:** Store pairs `(value, current_min)` inside the stack to achieve `O(1)` retrieval of the absolute minimum element at any given state.
