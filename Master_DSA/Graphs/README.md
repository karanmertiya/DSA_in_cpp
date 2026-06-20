# Graphs
## 🧠 Core Intuition
Vertices connected by edges representing networks. The holy grail of pathfinding and cyclic dependency logic.

## 🛠️ Dependencies & Prerequisites
You must know how to represent a graph as an Adjacency List and safely track visited nodes.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int V = 5;
    // Vector of Vectors (Best for contiguous 0-indexed nodes)
    vector<vector<int>> adj(V);
    
    // Hash Map (Best for arbitrary or string nodes)
    unordered_map<int, vector<int>> mapAdj;
    
    // Adding an undirected edge between u and v
    int u = 0, v = 1;
    adj[u].push_back(v);
    adj[v].push_back(u); 
    
    // Visited Array
    vector<bool> visited(V, false);
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
from collections import defaultdict

# Hash Map representation (Safest and easiest in Python)
adj = defaultdict(list)

# Adding an undirected edge
u, v = 0, 1
adj[u].append(v)
adj[v].append(u)

# Visited Set (Great for arbitrary node names)
visited = set()
visited.add(u)
```
</details>

## ⏱️ Complexity Cheatsheet
| Algorithm | Purpose | Time Complexity |
| :--- | :--- | :--- |
| **BFS / DFS** | Traversal, Connected Components | `O(V + E)` |
| **Dijkstra's** | Shortest Path (Positive Weights) | `O(E log V)` |
| **Bellman-Ford** | Shortest Path (Negative Weights) | `O(V * E)` |
| **Floyd-Warshall**| All-Pairs Shortest Path | `O(V^3)` |
| **Kruskal's** | Minimum Spanning Tree (MST) | `O(E log E)` |

## 💡 Elite Patterns
- **Topological Sort (Kahn's):** Used for Directed Acyclic Graphs (DAGs) to resolve prerequisite dependencies (e.g., Course Schedule). Tracks in-degrees of nodes.
- **Disjoint Set Union (DSU):** Operates on edges. Unifies sets to instantly determine if two nodes are in the same component, or if adding an edge creates a cycle.
- **Multi-Source BFS:** Start BFS with *all* target nodes initialized in the queue at time `t=0` (e.g., Rotting Oranges).
