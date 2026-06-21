# Day 23 24 Graphs Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 30%;">Example & Constraints</th>
      <th style="width: 15%;">Complexity</th>
      <th style="width: 35%;">Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Graph 01 Number Of Islands<br><br></b> <a href="https://leetcode.com/problems/number-of-islands/" target="_blank">LeetCode 200</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Constraint)</td>
      <td><b>Explanation:</b> Iterate through the grid. When a '1' is found, increment island count and use DFS to sink the island (turn connected '1's to '0's).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid, int i, int j) {&#10;    if(i &lt; 0 || i &gt;= grid.size() || j &lt; 0 || j &gt;= grid[0].size() || grid[i][j] == &#x27;0&#x27;) return;&#10;    grid[i][j] = &#x27;0&#x27;; // Sink&#10;    dfs(grid, i + 1, j);&#10;    dfs(grid, i - 1, j);&#10;    dfs(grid, i, j + 1);&#10;    dfs(grid, i, j - 1);&#10;}&#10;int numIslands(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(grid, i, j);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Graph 02 Course Schedule<br><br></b> <a href="https://leetcode.com/problems/course-schedule/" target="_blank">LeetCode 207</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> numCourses = 2, prerequisites = [[1,0]]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(V + E) (Constraint)<br><b>Space:</b> O(V + E)</td>
      <td><b>Explanation:</b> Kahn's Algorithm (BFS). Count in-degrees. Add courses with 0 in-degree to queue. Process queue, reducing in-degrees of neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canFinish(int numCourses, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; adj(numCourses);&#10;    std::vector&lt;int&gt; indegree(numCourses, 0);&#10;    for (auto&amp; pre : prerequisites) {&#10;        adj[pre[1]].push_back(pre[0]);&#10;        indegree[pre[0]]++;&#10;    }&#10;    std::queue&lt;int&gt; q;&#10;    for (int i = 0; i &lt; numCourses; i++) {&#10;        if (indegree[i] == 0) q.push(i);&#10;    }&#10;    int count = 0;&#10;    while (!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        count++;&#10;        for (int neighbor : adj[node]) {&#10;            indegree[neighbor]--;&#10;            if (indegree[neighbor] == 0) q.push(neighbor);&#10;        }&#10;    }&#10;    return count == numCourses;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Graph 03 Bipartite Graph<br><br></b> <a href="https://leetcode.com/problems/is-graph-bipartite/" target="_blank">LeetCode 785</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> graph = [[1,2,3],[0,2],[0,1,3],[0,2]]<br><b>Output:</b> false</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><b>Explanation:</b> BFS/DFS coloring approach. Color adjacent nodes with alternate colors (0 and 1). If an adjacent node has the SAME color, it's not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isBipartite(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; graph) {&#10;    int n = graph.size();&#10;    std::vector&lt;int&gt; color(n, -1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(color[i] != -1) continue;&#10;        std::queue&lt;int&gt; q;&#10;        q.push(i);&#10;        color[i] = 0;&#10;        while(!q.empty()) {&#10;            int node = q.front(); q.pop();&#10;            for(int neighbor : graph[node]) {&#10;                if(color[neighbor] == -1) {&#10;                    color[neighbor] = !color[node];&#10;                    q.push(neighbor);&#10;                } else if(color[neighbor] == color[node]) {&#10;                    return false;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Graph 04 Dijkstras Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td><b>Example 1:</b> Source = 0<br><b>Output:</b> distances array.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td><b>Explanation:</b> Min-heap (priority queue) to repeatedly extract the node with the minimum distance and relax its neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int adjNode = it[0], weight = it[1];&#10;            if(d + weight &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + weight;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Graph 05 Topological Sort<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/topological-sort/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> V = 4, adj = [[], [0], [0], [0]]<br><b>Output:</b> valid topological sort.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><b>Explanation:</b> Kahn's Algorithm (BFS) using in-degrees. Add nodes with 0 in-degree to a queue. Pop, append to result, and decrement in-degrees of neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(int i=0; i&lt;V; ++i) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; ++i) if(indegree[i] == 0) q.push(i);&#10;    vector&lt;int&gt; topo;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo.push_back(node);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Graph 06 Bellman Ford<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Apna College, Striver A Z</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> V=3, S=0, Edges=[[0,1,5],[1,2,-2],[2,1,-3]]<br><b>Output:</b> [-1]</td>
      <td><b>Time:</b> O(V * E)<br><b>Space:</b> O(V)</td>
      <td><b>Explanation:</b> Relax all edges V-1 times. To detect a negative cycle, relax one more time; if any distance updates, there's a negative cycle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bellman_ford(int V, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int S) {&#10;    vector&lt;int&gt; dist(V, 1e8);&#10;    dist[S] = 0;&#10;    for(int i=0; i&lt;V-1; i++) {&#10;        for(auto it: edges) {&#10;            int u = it[0], v = it[1], wt = it[2];&#10;            if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) {&#10;                dist[v] = dist[u] + wt;&#10;            }&#10;        }&#10;    }&#10;    for(auto it: edges) {&#10;        int u = it[0], v = it[1], wt = it[2];&#10;        if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) return {-1};&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Graph 07 Floyd Warshall<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Apna College, Striver A Z</details></td>
      <td><b>Example 1:</b><br><b>Output:</b> Shortest paths for all pairs (i, j).</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(1) in-place</td>
      <td><b>Explanation:</b> Multi-source shortest path. Try to go from i to j via every possible vertex k. Update `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void shortest_distance(vector&lt;vector&lt;int&gt;&gt;&amp; matrix){&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == -1) matrix[i][j] = 1e9;&#10;            if(i == j) matrix[i][j] = 0;&#10;        }&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                if(matrix[i][k] != 1e9 &amp;&amp; matrix[k][j] != 1e9) {&#10;                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == 1e9) matrix[i][j] = -1;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Graph 08 Mst Prims<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Apna College, Striver A Z</details></td>
      <td><b>Example 1:</b> Return the scalar sum of the MST.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(E + V)</td>
      <td><b>Explanation:</b> Prim's Algorithm. Use a Min-Heap `(weight, node)`. Always pick the smallest available edge connecting the MST to an unvisited node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int node = it.second, wt = it.first;&#10;        if(vis[node] == 1) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto it: adj[node]) {&#10;            int adjNode = it[0], edW = it[1];&#10;            if(!vis[adjNode]) pq.push({edW, adjNode});&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Graph 09 Strongly Connected Components Kosaraju<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Apna College, Striver A Z</details></td>
      <td><b>Example 1:</b> Return an integer count.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td><b>Explanation:</b> Kosaraju's Algo: 1) Sort nodes by finish time (Topo Sort DFS). 2) Transpose the graph (reverse edges). 3) DFS on transposed graph in order of finish time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt;&amp; vis, vector&lt;vector&lt;int&gt;&gt;&amp; adj, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it: adj[node]) if(!vis[it]) dfs(it, vis, adj, st);&#10;    st.push(node);&#10;}&#10;void dfs3(int node, vector&lt;int&gt;&amp; vis, vector&lt;int&gt; adjT[]) {&#10;    vis[node] = 1;&#10;    for(auto it: adjT[node]) if(!vis[it]) dfs3(it, vis, adjT);&#10;}&#10;int kosaraju(int V, vector&lt;vector&lt;int&gt;&gt;&amp; adj) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;V; i++) if(!vis[i]) dfs(i, vis, adj, st);&#10;    vector&lt;int&gt; adjT[V];&#10;    for(int i=0; i&lt;V; i++) {&#10;        vis[i] = 0;&#10;        for(auto it: adj[i]) adjT[it].push_back(i);&#10;    }&#10;    int scc = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top(); st.pop();&#10;        if(!vis[node]) {&#10;            scc++; dfs3(node, vis, adjT);&#10;        }&#10;    }&#10;    return scc;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Graph 10 Bipartite Graph DFS<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/bipartite-graph/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td><b>Example 1:</b> Return true/false.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><b>Explanation:</b> DFS. Color nodes with 0 and 1. If an adjacent node is uncolored, assign the opposite color and recurse. If it's colored and has the same color, it's not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfs(int node, int col, int color[], vector&lt;int&gt; adj[]) {&#10;    color[node] = col;&#10;    for(auto it: adj[node]) {&#10;        if(color[it] == -1) {&#10;            if(dfs(it, !col, color, adj) == false) return false;&#10;        } else if(color[it] == col) {&#10;            return false;&#10;        }&#10;    }&#10;    return true;&#10;}&#10;bool isBipartite(int V, vector&lt;int&gt;adj[]) {&#10;    int color[V];&#10;    for(int i=0; i&lt;V; i++) color[i] = -1;&#10;    for(int i=0; i&lt;V; i++) {&#10;        if(color[i] == -1) {&#10;            if(dfs(i, 0, color, adj) == false) return false;&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
