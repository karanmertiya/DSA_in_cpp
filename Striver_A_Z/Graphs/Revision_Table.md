# Graphs Revision Table

<table border="1">
  <thead>
    <tr>
      <th rowspan="2" style="width: 5%;">S.No</th>
      <th rowspan="2" style="width: 15%;">Problem Name</th>
      <th rowspan="2" style="width: 25%;">Example & Constraints</th>
      <th rowspan="2" style="width: 10%;">Complexity</th>
      <th colspan="2" style="width: 20%;">Conditions & Edge Cases</th>
      <th rowspan="2" style="width: 25%;">Logic</th>
    </tr>
    <tr>
      <th>Dependencies / Setup</th>
      <th>Edge Case Handling</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Graph 01 Number Of Islands<br><br></b> <a href='https://leetcode.com/problems/number-of-islands/' target='_blank'>LeetCode 200</a></td>
      <td><b>Example 1:</b> Input: grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]], Output: 3</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Constraint)</td>
      <td>-</td>
      <td><b>In-place Visited Check:</b> Sinking the island by changing '1' to '0' avoids needing a separate `visited` matrix.</td>
      <td><b>Explanation:</b> Iterate through the grid. When a '1' is found, increment island count and use DFS to sink the island (turn connected '1's to '0's).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid, int i, int j) {&#10;    if(i &lt; 0 || i &gt;= grid.size() || j &lt; 0 || j &gt;= grid[0].size() || grid[i][j] == &#x27;0&#x27;) return;&#10;    grid[i][j] = &#x27;0&#x27;; // Sink&#10;    dfs(grid, i + 1, j);&#10;    dfs(grid, i - 1, j);&#10;    dfs(grid, i, j + 1);&#10;    dfs(grid, i, j - 1);&#10;}&#10;int numIslands(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(grid, i, j);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Graph 02 Course Schedule<br><br></b> <a href='https://leetcode.com/problems/course-schedule/' target='_blank'>LeetCode 207</a></td>
      <td><b>Example 1:</b> Input: numCourses = 2, prerequisites = [[1,0]], Output: true</td>
      <td><b>Time:</b> O(V + E) (Constraint)<br><b>Space:</b> O(V + E)</td>
      <td><code>std::queue</code></td>
      <td><b>Graph Building:</b> Convert `prerequisites` edge list into an Adjacency List for fast neighbor lookups.</td>
      <td><b>Explanation:</b> Kahn's Algorithm (BFS). Count in-degrees. Add courses with 0 in-degree to queue. Process queue, reducing in-degrees of neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;bool canFinish(int numCourses, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; adj(numCourses);&#10;    std::vector&lt;int&gt; indegree(numCourses, 0);&#10;    for (auto&amp; pre : prerequisites) {&#10;        adj[pre[1]].push_back(pre[0]);&#10;        indegree[pre[0]]++;&#10;    }&#10;    std::queue&lt;int&gt; q;&#10;    for (int i = 0; i &lt; numCourses; i++) {&#10;        if (indegree[i] == 0) q.push(i);&#10;    }&#10;    int count = 0;&#10;    while (!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        count++;&#10;        for (int neighbor : adj[node]) {&#10;            indegree[neighbor]--;&#10;            if (indegree[neighbor] == 0) q.push(neighbor);&#10;        }&#10;    }&#10;    return count == numCourses;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Graph 03 Rotting Oranges<br><br></b> <a href='https://leetcode.com/problems/rotting-oranges/' target='_blank'>LeetCode 994</a></td>
      <td><b>Example 1:</b> Input: grid = [[2,1,1],[1,1,0],[0,1,1]], Output: 4</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(M * N)</td>
      <td><code>std::queue</code></td>
      <td><b>Unreachable Oranges:</b> Track total fresh oranges initially. If remaining fresh > 0 after BFS, return -1.</td>
      <td><b>Explanation:</b> Multi-source BFS. Put all initially rotten oranges in queue. Process level by level.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;int orangesRotting(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; grid) {&#10;    std::queue&lt;std::pair&lt;int, int&gt;&gt; q;&#10;    int fresh = 0, time = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == 2) q.push({i, j});&#10;            else if(grid[i][j] == 1) fresh++;&#10;        }&#10;    }&#10;    std::vector&lt;std::pair&lt;int, int&gt;&gt; dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};&#10;    while(!q.empty() &amp;&amp; fresh &gt; 0) {&#10;        int sz = q.size();&#10;        while(sz--) {&#10;            auto [r, c] = q.front(); q.pop();&#10;            for(auto&amp; d : dirs) {&#10;                int nr = r + d.first, nc = c + d.second;&#10;                if(nr &gt;= 0 &amp;&amp; nr &lt; grid.size() &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; grid[0].size() &amp;&amp; grid[nr][nc] == 1) {&#10;                    grid[nr][nc] = 2;&#10;                    q.push({nr, nc});&#10;                    fresh--;&#10;                }&#10;            }&#10;        }&#10;        time++;&#10;    }&#10;    return fresh == 0 ? time : -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Graph 04 Bipartite Graph<br><br></b> <a href='https://leetcode.com/problems/is-graph-bipartite/' target='_blank'>LeetCode 785</a></td>
      <td><b>Example 1:</b> Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]], Output: false</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><code>std::queue</code></td>
      <td><b>Disconnected Graph:</b> Must loop over all nodes `0` to `V-1` to ensure every disconnected component is checked.</td>
      <td><b>Explanation:</b> BFS/DFS coloring approach. Color adjacent nodes with alternate colors (0 and 1). If an adjacent node has the SAME color, it's not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;bool isBipartite(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; graph) {&#10;    int n = graph.size();&#10;    std::vector&lt;int&gt; color(n, -1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(color[i] != -1) continue;&#10;        std::queue&lt;int&gt; q;&#10;        q.push(i);&#10;        color[i] = 0;&#10;        while(!q.empty()) {&#10;            int node = q.front(); q.pop();&#10;            for(int neighbor : graph[node]) {&#10;                if(color[neighbor] == -1) {&#10;                    color[neighbor] = !color[node];&#10;                    q.push(neighbor);&#10;                } else if(color[neighbor] == color[node]) {&#10;                    return false;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Graph 06 Dijkstras Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Source = 0, Output: distances array.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td><code>#include &lt;queue&gt;</code></td>
      <td><b>Disconnected graph:</b> Distances remain infinity.</td>
      <td><b>Explanation:</b> Min-heap (priority queue) to repeatedly extract the node with the minimum distance and relax its neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int adjNode = it[0], weight = it[1];&#10;            if(d + weight &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + weight;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Graph 07 Topological Sort<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: V = 4, adj = [[], [0], [0], [0]], Output: valid topological sort.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><code>#include &lt;queue&gt;</code></td>
      <td><b>Cycles:</b> If cycle exists, result will not contain all V elements.</td>
      <td><b>Explanation:</b> Kahn's Algorithm (BFS) using in-degrees. Add nodes with 0 in-degree to a queue. Pop, append to result, and decrement in-degrees of neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(int i=0; i&lt;V; ++i) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; ++i) if(indegree[i] == 0) q.push(i);&#10;    vector&lt;int&gt; topo;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo.push_back(node);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Graph 08 Number Of Islands<br><br></b> <a href='https://leetcode.com/problems/number-of-islands/' target='_blank'>LeetCode 200</a></td>
      <td><b>Example 1:</b> Input: grid=[['1','1','0','0','0'],...], Output: 1</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) auxiliary</td>
      <td>-</td>
      <td><b>Empty Grid:</b> Returns 0.</td>
      <td><b>Explanation:</b> Traverse grid. Whenever a '1' is found, increment counter and trigger BFS/DFS to sink the island (mark '0').<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(vector&lt;vector&lt;char&gt;&gt;&amp; grid, int r, int c) {&#10;    if(r&lt;0 || c&lt;0 || r&gt;=grid.size() || c&gt;=grid[0].size() || grid[r][c] == &#x27;0&#x27;) return;&#10;    grid[r][c] = &#x27;0&#x27;;&#10;    dfs(grid, r+1, c); dfs(grid, r-1, c); dfs(grid, r, c+1); dfs(grid, r, c-1);&#10;}&#10;int numIslands(vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i=0; i&lt;grid.size(); i++) {&#10;        for(int j=0; j&lt;grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) { count++; dfs(grid, i, j); }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Graph 09 Course Schedule<br><br></b> <a href='https://leetcode.com/problems/course-schedule/' target='_blank'>LeetCode 207</a></td>
      <td><b>Example 1:</b> Input: numCourses = 2, prerequisites = [[1,0]], Output: true</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td><b>Multiple components:</b> Still works because we enqueue all 0-indegree nodes.</td>
      <td><b>Explanation:</b> Kahn's BFS or DFS cycle detection. Here Kahn's BFS is used. If topological sort contains all V vertices, then true.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canFinish(int V, vector&lt;vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    vector&lt;vector&lt;int&gt;&gt; adj(V);&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(auto it: prerequisites) {&#10;        adj[it[1]].push_back(it[0]);&#10;        indegree[it[0]]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; i++) if(indegree[i] == 0) q.push(i);&#10;    int count = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop(); count++;&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return count == V;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Graph 10 Bellman Ford<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: V=3, S=0, Edges=[[0,1,5],[1,2,-2],[2,1,-3]], Output: [-1]</td>
      <td><b>Time:</b> O(V * E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td><b>Disconnected Graphs:</b> Elements unreachable from source remain at 1e8.</td>
      <td><b>Explanation:</b> Relax all edges V-1 times. To detect a negative cycle, relax one more time; if any distance updates, there's a negative cycle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bellman_ford(int V, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int S) {&#10;    vector&lt;int&gt; dist(V, 1e8);&#10;    dist[S] = 0;&#10;    for(int i=0; i&lt;V-1; i++) {&#10;        for(auto it: edges) {&#10;            int u = it[0], v = it[1], wt = it[2];&#10;            if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) {&#10;                dist[v] = dist[u] + wt;&#10;            }&#10;        }&#10;    }&#10;    for(auto it: edges) {&#10;        int u = it[0], v = it[1], wt = it[2];&#10;        if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) return {-1};&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Graph 11 Floyd Warshall<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Output: Shortest paths for all pairs (i, j).</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(1) in-place</td>
      <td>-</td>
      <td><b>Unreachable nodes:</b> Represented by -1. Replace with 1e9 before algorithm, then back to -1.</td>
      <td><b>Explanation:</b> Multi-source shortest path. Try to go from i to j via every possible vertex k. Update `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void shortest_distance(vector&lt;vector&lt;int&gt;&gt;&amp; matrix){&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == -1) matrix[i][j] = 1e9;&#10;            if(i == j) matrix[i][j] = 0;&#10;        }&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                if(matrix[i][k] != 1e9 &amp;&amp; matrix[k][j] != 1e9) {&#10;                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == 1e9) matrix[i][j] = -1;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Graph 12 Mst Prims<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return the scalar sum of the MST.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(E + V)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Prim's Algorithm. Use a Min-Heap `(weight, node)`. Always pick the smallest available edge connecting the MST to an unvisited node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int node = it.second, wt = it.first;&#10;        if(vis[node] == 1) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto it: adj[node]) {&#10;            int adjNode = it[0], edW = it[1];&#10;            if(!vis[adjNode]) pq.push({edW, adjNode});&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Graph 13 Strongly Connected Components Kosaraju<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return an integer count.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Kosaraju's Algo: 1) Sort nodes by finish time (Topo Sort DFS). 2) Transpose the graph (reverse edges). 3) DFS on transposed graph in order of finish time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt;&amp; vis, vector&lt;vector&lt;int&gt;&gt;&amp; adj, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it: adj[node]) if(!vis[it]) dfs(it, vis, adj, st);&#10;    st.push(node);&#10;}&#10;void dfs3(int node, vector&lt;int&gt;&amp; vis, vector&lt;int&gt; adjT[]) {&#10;    vis[node] = 1;&#10;    for(auto it: adjT[node]) if(!vis[it]) dfs3(it, vis, adjT);&#10;}&#10;int kosaraju(int V, vector&lt;vector&lt;int&gt;&gt;&amp; adj) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;V; i++) if(!vis[i]) dfs(i, vis, adj, st);&#10;    vector&lt;int&gt; adjT[V];&#10;    for(int i=0; i&lt;V; i++) {&#10;        vis[i] = 0;&#10;        for(auto it: adj[i]) adjT[it].push_back(i);&#10;    }&#10;    int scc = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top(); st.pop();&#10;        if(!vis[node]) {&#10;            scc++; dfs3(node, vis, adjT);&#10;        }&#10;    }&#10;    return scc;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Graph 14 Topological Sort Dfs<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return array.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use DFS. Maintain a visited array. Once all adjacent nodes of a vertex are visited, push the vertex to a stack. Print the stack for the topological order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt;&amp; vis, stack&lt;int&gt;&amp; st, vector&lt;int&gt; adj[]) {&#10;    vis[node] = 1;&#10;    for(auto it: adj[node]) {&#10;        if(!vis[it]) dfs(it, vis, st, adj);&#10;    }&#10;    st.push(node);&#10;}&#10;vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;V; i++) {&#10;        if(!vis[i]) dfs(i, vis, st, adj);&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!st.empty()) { ans.push_back(st.top()); st.pop(); }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Graph 15 Kahn Algorithm Bfs<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Kahn's.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Compute in-degrees for all nodes. Push nodes with 0 in-degree to a queue. Pop, add to answer, and reduce in-degrees of neighbors. If a neighbor reaches 0, push it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    int indegree[V] = {0};&#10;    for(int i=0; i&lt;V; i++) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; i++) if(indegree[i] == 0) q.push(i);&#10;    vector&lt;int&gt; topo;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo.push_back(node);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Graph 16 Detect Cycle Directed Bfs<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return true if cycle exists.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> A DAG has a topological sort of exactly V elements. Use Kahn's BFS. If the number of elements pulled from the queue is < V, there's a cycle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isCyclic(int V, vector&lt;int&gt; adj[]) {&#10;    int indegree[V] = {0};&#10;    for(int i=0; i&lt;V; i++) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; i++) if(indegree[i] == 0) q.push(i);&#10;    int cnt = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        cnt++;&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return cnt != V;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Graph 17 Bipartite Graph Dfs<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/bipartite-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return true/false.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DFS. Color nodes with 0 and 1. If an adjacent node is uncolored, assign the opposite color and recurse. If it's colored and has the same color, it's not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfs(int node, int col, int color[], vector&lt;int&gt; adj[]) {&#10;    color[node] = col;&#10;    for(auto it: adj[node]) {&#10;        if(color[it] == -1) {&#10;            if(dfs(it, !col, color, adj) == false) return false;&#10;        } else if(color[it] == col) {&#10;            return false;&#10;        }&#10;    }&#10;    return true;&#10;}&#10;bool isBipartite(int V, vector&lt;int&gt;adj[]) {&#10;    int color[V];&#10;    for(int i=0; i&lt;V; i++) color[i] = -1;&#10;    for(int i=0; i&lt;V; i++) {&#10;        if(color[i] == -1) {&#10;            if(dfs(i, 0, color, adj) == false) return false;&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Graph 18 Alien Dictionary<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/alien-dictionary/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> words = ['baa', 'abcd', 'abca', 'cab', 'cad'], K = 4, Output: 'bdac'</td>
      <td><b>Time:</b> O(N * Len + K + E)<br><b>Space:</b> O(K + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Create a DAG based on mismatching characters between adjacent words. Use Kahn's algorithm (Topological Sort BFS) to find the character order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string findOrder(string dict[], int N, int K) {&#10;    vector&lt;int&gt; adj[K];&#10;    for(int i=0; i&lt;N-1; i++) {&#10;        string s1 = dict[i], s2 = dict[i+1];&#10;        int len = min(s1.size(), s2.size());&#10;        for(int ptr=0; ptr&lt;len; ptr++) {&#10;            if(s1[ptr] != s2[ptr]) {&#10;                adj[s1[ptr] - &#x27;a&#x27;].push_back(s2[ptr] - &#x27;a&#x27;);&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    vector&lt;int&gt; indegree(K, 0);&#10;    for(int i=0; i&lt;K; i++) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;K; i++) if(indegree[i] == 0) q.push(i);&#10;    string topo = &quot;&quot;;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo += char(node + &#x27;a&#x27;);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Graph 19 Shortest Path In Directed Acyclic Graph<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Topo Sort.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Perform Topological Sort. Then iterate through the topologically sorted vertices. For each vertex `u`, relax its neighbors: `dist[v] = min(dist[v], dist[u] + weight)`. Return `dist` array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void topoSort(int node, vector&lt;pair&lt;int, int&gt;&gt; adj[], vector&lt;int&gt;&amp; vis, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it : adj[node]) {&#10;        int v = it.first;&#10;        if(!vis[v]) topoSort(v, adj, vis, st);&#10;    }&#10;    st.push(node);&#10;}&#10;vector&lt;int&gt; shortestPath(int N, int M, vector&lt;vector&lt;int&gt;&gt;&amp; edges) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; adj[N];&#10;    for(int i=0; i&lt;M; i++) {&#10;        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];&#10;        adj[u].push_back({v, wt});&#10;    }&#10;    vector&lt;int&gt; vis(N, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;N; i++) {&#10;        if(!vis[i]) topoSort(i, adj, vis, st);&#10;    }&#10;    vector&lt;int&gt; dist(N, 1e9);&#10;    dist[0] = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top();&#10;        st.pop();&#10;        if(dist[node] != 1e9) {&#10;            for(auto it : adj[node]) {&#10;                int v = it.first, wt = it.second;&#10;                if(dist[node] + wt &lt; dist[v]) {&#10;                    dist[v] = dist[node] + wt;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;N; i++) if(dist[i] == 1e9) dist[i] = -1;&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Graph 20 Shortest Path In Undirected Graph With Unit Distance<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> BFS approach.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Standard BFS starting from source. Distance of neighbors is `dist[u] + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; shortestPath(vector&lt;vector&lt;int&gt;&gt;&amp; edges, int N, int M, int src){&#10;    vector&lt;int&gt; adj[N];&#10;    for(int i=0; i&lt;M; i++) {&#10;        adj[edges[i][0]].push_back(edges[i][1]);&#10;        adj[edges[i][1]].push_back(edges[i][0]);&#10;    }&#10;    vector&lt;int&gt; dist(N, 1e9);&#10;    dist[src] = 0;&#10;    queue&lt;int&gt; q;&#10;    q.push(src);&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        for(int it : adj[node]) {&#10;            if(dist[node] + 1 &lt; dist[it]) {&#10;                dist[it] = dist[node] + 1;&#10;                q.push(it);&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;N; i++) if(dist[i] == 1e9) dist[i] = -1;&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Graph 21 Dijkstras Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> PQ based Dijkstra.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Min-Heap. `dist` array initialized to infinity. Push `{0, src}` to PQ. Pop `node`. If `dist[node] + weight < dist[adjNode]`, update `dist[adjNode]` and push `{dist[adjNode], adjNode}` to PQ.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int dis = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int edgeWeight = it[1];&#10;            int adjNode = it[0];&#10;            if(dis + edgeWeight &lt; dist[adjNode]) {&#10;                dist[adjNode] = dis + edgeWeight;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Graph 22 Bellman Ford Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Detect negative cycle.</td>
      <td><b>Time:</b> O(V * E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Relax all E edges V-1 times. If any edge can still be relaxed in the Vth iteration, then there's a negative cycle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bellman_ford(int V, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int S) {&#10;    vector&lt;int&gt; dist(V, 1e8);&#10;    dist[S] = 0;&#10;    for(int i=0; i&lt;V-1; i++) {&#10;        for(auto it : edges) {&#10;            int u = it[0], v = it[1], wt = it[2];&#10;            if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) {&#10;                dist[v] = dist[u] + wt;&#10;            }&#10;        }&#10;    }&#10;    for(auto it : edges) {&#10;        int u = it[0], v = it[1], wt = it[2];&#10;        if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) return {-1};&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Graph 23 Floyd Warshall Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> All pairs shortest path.</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(V^2) or O(1) if in-place</td>
      <td>-</td>
      <td><b>Unreachable:</b> Replace -1 with infinity before loop, revert back to -1 after.</td>
      <td><b>Explanation:</b> Iterate `k` (via node) from 0 to V-1. Iterate `i` and `j`. `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`. If `matrix[i][i] < 0`, negative cycle exists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void shortest_distance(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == -1) matrix[i][j] = 1e9;&#10;            if(i == j) matrix[i][j] = 0;&#10;        }&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == 1e9) matrix[i][j] = -1;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Graph 24 Minimum Spanning Tree<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Kruskal or Prim's.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Prim's Algorithm. Push `{0, 0}` to Min-Heap. If node is visited, continue. Mark visited, add weight to sum. Push all adjacent unvisited nodes to Heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int wt = it.first, node = it.second;&#10;        if(vis[node]) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto vec : adj[node]) {&#10;            int adjNode = vec[0], edW = vec[1];&#10;            if(!vis[adjNode]) {&#10;                pq.push({edW, adjNode});&#10;            }&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Graph 25 Prims Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> MST.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Same as previous. Min Heap of `{weight, node}`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int wt = it.first, node = it.second;&#10;        if(vis[node]) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto vec : adj[node]) {&#10;            int adjNode = vec[0], edW = vec[1];&#10;            if(!vis[adjNode]) {&#10;                pq.push({edW, adjNode});&#10;            }&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Graph 26 Kruskals Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DSU approach.</td>
      <td><b>Time:</b> O(E log E + E * alpha)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort all edges by weight. Iterate through sorted edges. Use Disjoint Set Union (DSU) to check if adding the edge forms a cycle. If not, add edge to MST and union the sets.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;    vector&lt;int&gt; rank, parent, size;&#10;public:&#10;    DisjointSet(int n) {&#10;        rank.resize(n + 1, 0);&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1);&#10;        for(int i=0; i&lt;=n; i++) {&#10;            parent[i] = i;&#10;            size[i] = 1;&#10;        }&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt; edges;&#10;    for(int i=0; i&lt;V; i++) {&#10;        for(auto it : adj[i]) {&#10;            int adjNode = it[0], wt = it[1];&#10;            int node = i;&#10;            edges.push_back({wt, {node, adjNode}});&#10;        }&#10;    }&#10;    sort(edges.begin(), edges.end());&#10;    DisjointSet ds(V);&#10;    int sum = 0;&#10;    for(auto it : edges) {&#10;        int wt = it.first, u = it.second.first, v = it.second.second;&#10;        if(ds.findUPar(u) != ds.findUPar(v)) {&#10;            sum += wt;&#10;            ds.unionBySize(u, v);&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Graph 27 Strongly Connected Components Kosarajus Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Reverse graph.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Kosaraju's Algorithm. 1. Topo sort the graph to get finish times (push to stack on completion). 2. Reverse all edges. 3. Pop from stack and run DFS on the reversed graph. Each successful DFS from stack gives one SCC.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt; adj[], vector&lt;int&gt;&amp; vis, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it : adj[node]) if(!vis[it]) dfs(it, adj, vis, st);&#10;    st.push(node);&#10;}&#10;void dfs2(int node, vector&lt;int&gt; adjT[], vector&lt;int&gt;&amp; vis) {&#10;    vis[node] = 1;&#10;    for(auto it : adjT[node]) if(!vis[it]) dfs2(it, adjT, vis);&#10;}&#10;int kosaraju(int V, vector&lt;int&gt; adj[]) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;V; i++) {&#10;        if(!vis[i]) dfs(i, adj, vis, st);&#10;    }&#10;    vector&lt;int&gt; adjT[V];&#10;    for(int i=0; i&lt;V; i++) {&#10;        vis[i] = 0;&#10;        for(auto it : adj[i]) adjT[it].push_back(i);&#10;    }&#10;    int scc = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top(); st.pop();&#10;        if(!vis[node]) {&#10;            scc++;&#10;            dfs2(node, adjT, vis);&#10;        }&#10;    }&#10;    return scc;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Graph 28 Bridges In Graph<br><br></b> <a href='https://leetcode.com/problems/critical-connections-in-a-network/' target='_blank'>LeetCode 1192</a></td>
      <td><b>Example 1:</b> Tarjan's algorithm.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Tarjan's algorithm. Maintain `tin` (time of insertion) and `low` (lowest time reachable). If `low[neighbor] > tin[node]`, the edge `(node, neighbor)` is a bridge. Update `low[node] = min(low[node], low[neighbor])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int timer = 1;&#10;void dfs(int node, int parent, vector&lt;int&gt;&amp; vis, vector&lt;int&gt; adj[], int tin[], int low[], vector&lt;vector&lt;int&gt;&gt;&amp; bridges) {&#10;    vis[node] = 1;&#10;    tin[node] = low[node] = timer++;&#10;    for(auto it : adj[node]) {&#10;        if(it == parent) continue;&#10;        if(vis[it] == 0) {&#10;            dfs(it, node, vis, adj, tin, low, bridges);&#10;            low[node] = min(low[node], low[it]);&#10;            if(low[it] &gt; tin[node]) bridges.push_back({node, it});&#10;        } else {&#10;            low[node] = min(low[node], low[it]);&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; criticalConnections(int n, vector&lt;vector&lt;int&gt;&gt;&amp; connections) {&#10;    vector&lt;int&gt; adj[n];&#10;    for(auto it : connections) {&#10;        adj[it[0]].push_back(it[1]);&#10;        adj[it[1]].push_back(it[0]);&#10;    }&#10;    vector&lt;int&gt; vis(n, 0);&#10;    int tin[n];&#10;    int low[n];&#10;    vector&lt;vector&lt;int&gt;&gt; bridges;&#10;    dfs(0, -1, vis, adj, tin, low, bridges);&#10;    return bridges;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Graph 29 Articulation Point I<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/articulation-point-1/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Tarjan's algorithm with discovery times.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain `tin` (insertion time) and `low` (lowest insertion time reachable). A node `u` is an articulation point if `low[v] >= tin[u]` (and it's not root). If root, it's an articulation point if it has >1 children in DFS tree.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int timer = 0;&#10;void dfs(int node, int parent, vector&lt;int&gt; &amp;vis, int tin[], int low[], vector&lt;int&gt; &amp;mark, vector&lt;int&gt;adj[]) {&#10;    vis[node] = 1;&#10;    tin[node] = low[node] = timer++;&#10;    int child = 0;&#10;    for(auto it : adj[node]) {&#10;        if(it == parent) continue;&#10;        if(!vis[it]) {&#10;            dfs(it, node, vis, tin, low, mark, adj);&#10;            low[node] = min(low[node], low[it]);&#10;            if(low[it] &gt;= tin[node] &amp;&amp; parent != -1) {&#10;                mark[node] = 1;&#10;            }&#10;            child++;&#10;        } else {&#10;            low[node] = min(low[node], tin[it]);&#10;        }&#10;    }&#10;    if(child &gt; 1 &amp;&amp; parent == -1) {&#10;        mark[node] = 1;&#10;    }&#10;}&#10;vector&lt;int&gt; articulationPoints(int V, vector&lt;int&gt;adj[]) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    int tin[V];&#10;    int low[V];&#10;    vector&lt;int&gt; mark(V, 0);&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(!vis[i]) {&#10;            dfs(i, -1, vis, tin, low, mark, adj);&#10;        }&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(mark[i] == 1) ans.push_back(i);&#10;    }&#10;    if(ans.size() == 0) return {-1};&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Graph 30 Number Of Provinces Dsu<br><br></b> <a href='https://leetcode.com/problems/number-of-provinces/' target='_blank'>LeetCode 547</a></td>
      <td><b>Example 1:</b> Connect elements, count unique parents.</td>
      <td><b>Time:</b> O(N^2 * alpha(N))<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Create DSU of size `n`. For every edge in `isConnected`, union the two nodes. The number of provinces is the number of nodes where `find(i) == i`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;    vector&lt;int&gt; parent, size;&#10;public:&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int findCircleNum(vector&lt;vector&lt;int&gt;&gt;&amp; isConnected) {&#10;    int n = isConnected.size();&#10;    DisjointSet ds(n);&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(isConnected[i][j] == 1) ds.unionBySize(i, j);&#10;        }&#10;    }&#10;    int cnt = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(ds.findUPar(i) == i) cnt++;&#10;    }&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Graph 31 Accounts Merge<br><br></b> <a href='https://leetcode.com/problems/accounts-merge/' target='_blank'>LeetCode 721</a></td>
      <td><b>Example 1:</b> DSU on accounts using emails.</td>
      <td><b>Time:</b> O(N log N * alpha(N)) where N is total emails<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Map each email to an account index. If an email is seen again, union the current account index with the previously mapped account index. Finally, group emails by their root account index, sort them, and attach the name.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;public:&#10;    vector&lt;int&gt; parent, size;&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;vector&lt;vector&lt;string&gt;&gt; accountsMerge(vector&lt;vector&lt;string&gt;&gt;&amp; accounts) {&#10;    int n = accounts.size();&#10;    DisjointSet ds(n);&#10;    unordered_map&lt;string, int&gt; mapMailNode;&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=1; j&lt;accounts[i].size(); j++) {&#10;            string mail = accounts[i][j];&#10;            if(mapMailNode.find(mail) == mapMailNode.end()) {&#10;                mapMailNode[mail] = i;&#10;            } else {&#10;                ds.unionBySize(i, mapMailNode[mail]);&#10;            }&#10;        }&#10;    }&#10;    vector&lt;string&gt; mergedMail[n];&#10;    for(auto it : mapMailNode) {&#10;        string mail = it.first;&#10;        int node = ds.findUPar(it.second);&#10;        mergedMail[node].push_back(mail);&#10;    }&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(mergedMail[i].size() == 0) continue;&#10;        sort(mergedMail[i].begin(), mergedMail[i].end());&#10;        vector&lt;string&gt; temp;&#10;        temp.push_back(accounts[i][0]);&#10;        for(auto it : mergedMail[i]) temp.push_back(it);&#10;        ans.push_back(temp);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Graph 32 Number Of Operations To Make Network Connected<br><br></b> <a href='https://leetcode.com/problems/number-of-operations-to-make-network-connected/' target='_blank'>LeetCode 1319</a></td>
      <td><b>Example 1:</b> Extra edges and connected components.</td>
      <td><b>Time:</b> O(E * alpha(N))<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If total edges < n - 1, impossible. Use DSU to count number of connected components `C` and number of extra edges `E`. An edge is extra if `find(u) == find(v)`. We need `C - 1` edges to connect `C` components. Since total edges >= n - 1, we guaranteed have enough extra edges. Answer is `C - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int makeConnected(int n, vector&lt;vector&lt;int&gt;&gt;&amp; connections) {&#10;    if(connections.size() &lt; n - 1) return -1;&#10;    vector&lt;int&gt; parent(n);&#10;    for(int i=0; i&lt;n; i++) parent[i] = i;&#10;    function&lt;int(int)&gt; find = [&amp;](int i) {&#10;        return parent[i] == i ? i : parent[i] = find(parent[i]);&#10;    };&#10;    int components = n;&#10;    for(auto&amp; edge : connections) {&#10;        int u = find(edge[0]);&#10;        int v = find(edge[1]);&#10;        if(u != v) {&#10;            parent[u] = v;&#10;            components--;&#10;        }&#10;    }&#10;    return components - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Graph 33 Most Stones Removed With Same Row Or Column<br><br></b> <a href='https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/' target='_blank'>LeetCode 947</a></td>
      <td><b>Example 1:</b> Treat rows and columns as nodes.</td>
      <td><b>Time:</b> O(N * alpha(N))<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Imagine rows and columns are nodes in a bipartite graph. A stone at `(r, c)` connects row `r` and column `c`. The answer is `total_stones - number_of_connected_components`. We can map cols to `col + 10001` to use a single DSU.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeStones(vector&lt;vector&lt;int&gt;&gt;&amp; stones) {&#10;    unordered_map&lt;int, int&gt; parent;&#10;    int components = 0;&#10;    function&lt;int(int)&gt; find = [&amp;](int i) {&#10;        if(parent.find(i) == parent.end()) {&#10;            parent[i] = i;&#10;            components++;&#10;        }&#10;        if(parent[i] == i) return i;&#10;        return parent[i] = find(parent[i]);&#10;    };&#10;    auto unionNodes = [&amp;](int u, int v) {&#10;        int root_u = find(u);&#10;        int root_v = find(v);&#10;        if(root_u != root_v) {&#10;            parent[root_u] = root_v;&#10;            components--;&#10;        }&#10;    };&#10;    for(auto&amp; stone : stones) {&#10;        unionNodes(stone[0], ~stone[1]); // ~x makes columns distinct from rows&#10;    }&#10;    return stones.size() - components;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Graph 34 Making A Large Island<br><br></b> <a href='https://leetcode.com/problems/making-a-large-island/' target='_blank'>LeetCode 827</a></td>
      <td><b>Example 1:</b> Component sizes with DSU.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Step 1: Use DSU to connect all adjacent 1s and calculate the size of each component. Step 2: For each 0, check its 4 neighbors. Find the unique roots of those neighbors. The potential new island size is `1 + sum(size[root])` for each unique root. Find max potential size. Handle case where matrix is all 1s.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;public:&#10;    vector&lt;int&gt; parent, size;&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i=0; i&lt;=n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u), ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int largestIsland(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    DisjointSet ds(n * n);&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    for(int r=0; r&lt;n; r++) {&#10;        for(int c=0; c&lt;n; c++) {&#10;            if(grid[r][c] == 0) continue;&#10;            for(int i=0; i&lt;4; i++) {&#10;                int nr = r + dr[i], nc = c + dc[i];&#10;                if(nr&gt;=0 &amp;&amp; nr&lt;n &amp;&amp; nc&gt;=0 &amp;&amp; nc&lt;n &amp;&amp; grid[nr][nc] == 1) {&#10;                    int nodeNo = r * n + c;&#10;                    int adjNodeNo = nr * n + nc;&#10;                    ds.unionBySize(nodeNo, adjNodeNo);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    int mx = 0;&#10;    for(int r=0; r&lt;n; r++) {&#10;        for(int c=0; c&lt;n; c++) {&#10;            if(grid[r][c] == 1) continue;&#10;            set&lt;int&gt; components;&#10;            for(int i=0; i&lt;4; i++) {&#10;                int nr = r + dr[i], nc = c + dc[i];&#10;                if(nr&gt;=0 &amp;&amp; nr&lt;n &amp;&amp; nc&gt;=0 &amp;&amp; nc&lt;n &amp;&amp; grid[nr][nc] == 1) {&#10;                    components.insert(ds.findUPar(nr * n + nc));&#10;                }&#10;            }&#10;            int sizeTotal = 0;&#10;            for(auto it : components) sizeTotal += ds.size[it];&#10;            mx = max(mx, sizeTotal + 1);&#10;        }&#10;    }&#10;    for(int cell=0; cell&lt;n*n; cell++) mx = max(mx, ds.size[ds.findUPar(cell)]);&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Graph 35 Swim In Rising Water<br><br></b> <a href='https://leetcode.com/problems/swim-in-rising-water/' target='_blank'>LeetCode 778</a></td>
      <td><b>Example 1:</b> Dijkstra-like or Binary Search + BFS.</td>
      <td><b>Time:</b> O(N^2 log N)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a priority queue (Dijkstra variant). The cost to reach a cell is `max(cost_of_previous_cell, grid[r][c])`. Extract min cost cell, relax neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int swimInWater(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    vector&lt;vector&lt;int&gt;&gt; dist(n, vector&lt;int&gt;(n, 1e9));&#10;    dist[0][0] = grid[0][0];&#10;    pq.push({grid[0][0], 0, 0});&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    while(!pq.empty()) {&#10;        auto it = pq.top();&#10;        pq.pop();&#10;        int d = it[0], r = it[1], c = it[2];&#10;        if(r == n-1 &amp;&amp; c == n-1) return d;&#10;        for(int i=0; i&lt;4; i++) {&#10;            int nr = r + dr[i], nc = c + dc[i];&#10;            if(nr&gt;=0 &amp;&amp; nr&lt;n &amp;&amp; nc&gt;=0 &amp;&amp; nc&lt;n) {&#10;                int next_d = max(d, grid[nr][nc]);&#10;                if(next_d &lt; dist[nr][nc]) {&#10;                    dist[nr][nc] = next_d;&#10;                    pq.push({next_d, nr, nc});&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Graph 36 Word Ladder I<br><br></b> <a href='https://leetcode.com/problems/word-ladder/' target='_blank'>LeetCode 127</a></td>
      <td><b>Example 1:</b> BFS level by level.</td>
      <td><b>Time:</b> O(N * M * 26) where N is words, M is word length<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> BFS. Start from `beginWord`. In each step, change one character from 'a' to 'z' and check if new word is in `wordList`. If yes, push to queue, erase from `wordList` to avoid loops, and continue. Track level/steps.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int ladderLength(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;pair&lt;string, int&gt;&gt; q;&#10;    q.push({beginWord, 1});&#10;    st.erase(beginWord);&#10;    while(!q.empty()) {&#10;        string word = q.front().first;&#10;        int steps = q.front().second;&#10;        q.pop();&#10;        if(word == endWord) return steps;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            char original = word[i];&#10;            for(char ch=&#x27;a&#x27;; ch&lt;=&#x27;z&#x27;; ch++) {&#10;                word[i] = ch;&#10;                if(st.find(word) != st.end()) {&#10;                    st.erase(word);&#10;                    q.push({word, steps + 1});&#10;                }&#10;            }&#10;            word[i] = original;&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Graph 37 Word Ladder Ii<br><br></b> <a href='https://leetcode.com/problems/word-ladder-ii/' target='_blank'>LeetCode 126</a></td>
      <td><b>Example 1:</b> BFS for distance, DFS for paths.</td>
      <td><b>Time:</b> O(V + E + Paths)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> BFS to find minimum steps to reach each word. Then DFS starting from `endWord` backwards to `beginWord`, only exploring paths where `dist[next_word] == dist[curr_word] - 1`. Reverse the built paths.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">unordered_map&lt;string, int&gt; mpp;&#10;vector&lt;vector&lt;string&gt;&gt; ans;&#10;string b;&#10;void dfs(string word, vector&lt;string&gt;&amp; seq) {&#10;    if(word == b) {&#10;        reverse(seq.begin(), seq.end());&#10;        ans.push_back(seq);&#10;        reverse(seq.begin(), seq.end());&#10;        return;&#10;    }&#10;    int steps = mpp[word];&#10;    for(int i=0; i&lt;word.size(); i++) {&#10;        char original = word[i];&#10;        for(char ch=&#x27;a&#x27;; ch&lt;=&#x27;z&#x27;; ch++) {&#10;            word[i] = ch;&#10;            if(mpp.find(word) != mpp.end() &amp;&amp; mpp[word] + 1 == steps) {&#10;                seq.push_back(word);&#10;                dfs(word, seq);&#10;                seq.pop_back();&#10;            }&#10;        }&#10;        word[i] = original;&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; findLadders(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;string&gt; q;&#10;    b = beginWord;&#10;    q.push({beginWord});&#10;    mpp[beginWord] = 1;&#10;    int sz = beginWord.size();&#10;    st.erase(beginWord);&#10;    while(!q.empty()) {&#10;        string word = q.front();&#10;        int steps = mpp[word];&#10;        q.pop();&#10;        if(word == endWord) break;&#10;        for(int i=0; i&lt;sz; i++) {&#10;            char original = word[i];&#10;            for(char ch=&#x27;a&#x27;; ch&lt;=&#x27;z&#x27;; ch++) {&#10;                word[i] = ch;&#10;                if(st.count(word)) {&#10;                    q.push(word);&#10;                    st.erase(word);&#10;                    mpp[word] = steps + 1;&#10;                }&#10;            }&#10;            word[i] = original;&#10;        }&#10;    }&#10;    if(mpp.find(endWord) != mpp.end()) {&#10;        vector&lt;string&gt; seq;&#10;        seq.push_back(endWord);&#10;        dfs(endWord, seq);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Graph 38 Network Delay Time<br><br></b> <a href='https://leetcode.com/problems/network-delay-time/' target='_blank'>LeetCode 743</a></td>
      <td><b>Example 1:</b> Dijkstra's to find max shortest path.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Standard Dijkstra's shortest path from node `k`. Return the maximum value in the distances array. If any node remains unvisited (dist == inf), return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int networkDelayTime(vector&lt;vector&lt;int&gt;&gt;&amp; times, int n, int k) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; adj[n+1];&#10;    for(auto t : times) adj[t[0]].push_back({t[1], t[2]});&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(n+1, 1e9);&#10;    dist[k] = 0;&#10;    pq.push({0, k});&#10;    while(!pq.empty()) {&#10;        int time = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int adjNode = it.first;&#10;            int wt = it.second;&#10;            if(time + wt &lt; dist[adjNode]) {&#10;                dist[adjNode] = time + wt;&#10;                pq.push({time + wt, adjNode});&#10;            }&#10;        }&#10;    }&#10;    int mx = 0;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        if(dist[i] == 1e9) return -1;&#10;        mx = max(mx, dist[i]);&#10;    }&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Graph 39 Cheapest Flights Within K Stops<br><br></b> <a href='https://leetcode.com/problems/cheapest-flights-within-k-stops/' target='_blank'>LeetCode 787</a></td>
      <td><b>Example 1:</b> Dijkstra's with Stops / BFS.</td>
      <td><b>Time:</b> O(E)<br><b>Space:</b> O(N + E)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a queue storing `(stops, node, cost)`. We don't need a priority queue because stops increase uniformly by 1. Distance array stores min cost to reach each node. Only push to queue if new cost is cheaper. If `stops > k`, skip.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findCheapestPrice(int n, vector&lt;vector&lt;int&gt;&gt;&amp; flights, int src, int dst, int k) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; adj(n);&#10;    for(auto&amp; f : flights) adj[f[0]].push_back({f[1], f[2]});&#10;    queue&lt;vector&lt;int&gt;&gt; q; // {stops, node, cost}&#10;    q.push({0, src, 0});&#10;    vector&lt;int&gt; dist(n, INT_MAX);&#10;    dist[src] = 0;&#10;    while(!q.empty()) {&#10;        auto curr = q.front(); q.pop();&#10;        int stops = curr[0], node = curr[1], cost = curr[2];&#10;        if(stops &gt; k) continue;&#10;        for(auto&amp; neighbor : adj[node]) {&#10;            int nextNode = neighbor.first;&#10;            int edgeWeight = neighbor.second;&#10;            if(cost + edgeWeight &lt; dist[nextNode] &amp;&amp; stops &lt;= k) {&#10;                dist[nextNode] = cost + edgeWeight;&#10;                q.push({stops + 1, nextNode, cost + edgeWeight});&#10;            }&#10;        }&#10;    }&#10;    return dist[dst] == INT_MAX ? -1 : dist[dst];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Graph 40 Minimum Multiplications To Reach End<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> BFS / Dijkstra's with unit weights.</td>
      <td><b>Time:</b> O(100000 * N)<br><b>Space:</b> O(100000)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Since each multiplication is 1 step, we can use BFS. The 'nodes' are values from 0 to 99999. Use an array `dist` initialized to infinity. Push `start` to queue. For each popped node, multiply by all array elements `% 100000`. If we find a shorter path, push to queue.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumMultiplications(vector&lt;int&gt;&amp; arr, int start, int end) {&#10;    if(start == end) return 0;&#10;    queue&lt;pair&lt;int, int&gt;&gt; q;&#10;    q.push({start, 0});&#10;    vector&lt;int&gt; dist(100000, 1e9);&#10;    dist[start] = 0;&#10;    int mod = 100000;&#10;    while(!q.empty()) {&#10;        int node = q.front().first;&#10;        int steps = q.front().second;&#10;        q.pop();&#10;        for(int it : arr) {&#10;            int num = (node * it) % mod;&#10;            if(steps + 1 &lt; dist[num]) {&#10;                dist[num] = steps + 1;&#10;                if(num == end) return steps + 1;&#10;                q.push({num, steps + 1});&#10;            }&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Graph 41 Number Of Ways To Arrive At Destination<br><br></b> <a href='https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/' target='_blank'>LeetCode 1976</a></td>
      <td><b>Example 1:</b> Dijkstra's with Ways Count.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V + E)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Modify Dijkstra's. Keep `dist` array and `ways` array. When relaxing an edge: if `curr_dist + weight < dist[neighbor]`, update `dist`, push to PQ, and `ways[neighbor] = ways[curr_node]`. If `curr_dist + weight == dist[neighbor]`, `ways[neighbor] = (ways[neighbor] + ways[curr_node]) % MOD`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPaths(int n, vector&lt;vector&lt;int&gt;&gt;&amp; roads) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; adj(n);&#10;    for(auto&amp; r : roads) {&#10;        adj[r[0]].push_back({r[1], r[2]});&#10;        adj[r[1]].push_back({r[0], r[2]});&#10;    }&#10;    priority_queue&lt;pair&lt;long long, int&gt;, vector&lt;pair&lt;long long, int&gt;&gt;, greater&lt;pair&lt;long long, int&gt;&gt;&gt; pq;&#10;    vector&lt;long long&gt; dist(n, 1e18);&#10;    vector&lt;int&gt; ways(n, 0);&#10;    dist[0] = 0;&#10;    ways[0] = 1;&#10;    pq.push({0, 0});&#10;    int mod = 1e9 + 7;&#10;    while(!pq.empty()) {&#10;        long long d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        if(d &gt; dist[node]) continue;&#10;        for(auto&amp; it : adj[node]) {&#10;            int adjNode = it.first;&#10;            long long edW = it.second;&#10;            if(d + edW &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + edW;&#10;                ways[adjNode] = ways[node];&#10;                pq.push({d + edW, adjNode});&#10;            } else if(d + edW == dist[adjNode]) {&#10;                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;&#10;            }&#10;        }&#10;    }&#10;    return ways[n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Graph 42 Find The City With The Smallest Number Of Neighbors At A Threshold Distance<br><br></b> <a href='https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/' target='_blank'>LeetCode 1334</a></td>
      <td><b>Example 1:</b> Floyd-Warshall Algorithm.</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(V^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Floyd-Warshall to find shortest paths between all pairs of nodes. For each city, count the number of reachable cities within `distanceThreshold`. Return the city with the minimum count (and greatest ID on tie).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTheCity(int n, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int distanceThreshold) {&#10;    vector&lt;vector&lt;int&gt;&gt; dist(n, vector&lt;int&gt;(n, 1e9));&#10;    for(int i=0; i&lt;n; i++) dist[i][i] = 0;&#10;    for(auto&amp; e : edges) {&#10;        dist[e[0]][e[1]] = e[2];&#10;        dist[e[1]][e[0]] = e[2];&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                if(dist[i][k] != 1e9 &amp;&amp; dist[k][j] != 1e9) {&#10;                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    int minCities = n, ansCity = -1;&#10;    for(int i=0; i&lt;n; i++) {&#10;        int cnt = 0;&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(dist[i][j] &lt;= distanceThreshold) cnt++;&#10;        }&#10;        if(cnt &lt;= minCities) {&#10;            minCities = cnt;&#10;            ansCity = i;&#10;        }&#10;    }&#10;    return ansCity;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Graph 43 Minimum Spanning Tree Prim<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Prim's Algorithm using Min-Heap.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(E + V)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Start from node 0. Push `(0, 0)` -> `(weight, node)` into PQ. Maintain `visited` array. Pop min edge. If not visited, mark visited, add weight to sum. Traverse its neighbors; if not visited, push to PQ.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top();&#10;        pq.pop();&#10;        int node = it.second;&#10;        int wt = it.first;&#10;        if(vis[node]) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto&amp; neighbor : adj[node]) {&#10;            int adjNode = neighbor[0];&#10;            int edW = neighbor[1];&#10;            if(!vis[adjNode]) {&#10;                pq.push({edW, adjNode});&#10;            }&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Graph 44 Kruskals Minimum Spanning Tree Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Disjoint Set / Union Find.</td>
      <td><b>Time:</b> O(E log E)<br><b>Space:</b> O(E + V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Extract all edges as `(weight, u, v)`. Sort edges by weight. Iterate through sorted edges. Use Disjoint Set (Union-Find) to check if `u` and `v` are in the same component. If not, union them and add weight to sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;    vector&lt;int&gt; parent, rank;&#10;public:&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        rank.resize(n + 1, 0);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionByRank(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(rank[ulp_u] &lt; rank[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;        } else if(rank[ulp_v] &lt; rank[ulp_u]) {&#10;            parent[ulp_v] = ulp_u;&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            rank[ulp_u]++;&#10;        }&#10;    }&#10;};&#10;int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt; edges;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        for(auto&amp; it : adj[i]) {&#10;            int adjNode = it[0];&#10;            int wt = it[1];&#10;            edges.push_back({wt, {i, adjNode}});&#10;        }&#10;    }&#10;    sort(edges.begin(), edges.end());&#10;    DisjointSet ds(V);&#10;    int mstWt = 0;&#10;    for(auto&amp; it : edges) {&#10;        int wt = it.first;&#10;        int u = it.second.first;&#10;        int v = it.second.second;&#10;        if(ds.findUPar(u) != ds.findUPar(v)) {&#10;            mstWt += wt;&#10;            ds.unionByRank(u, v);&#10;        }&#10;    }&#10;    return mstWt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Graph 45 Number Of Provinces Disjoint Set<br><br></b> <a href='https://leetcode.com/problems/number-of-provinces/' target='_blank'>LeetCode 547</a></td>
      <td><b>Example 1:</b> Counting Unique Parents in DSU.</td>
      <td><b>Time:</b> O(V^2 * alpha)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Initialize Disjoint Set for `n` nodes. Iterate through `isConnected` matrix. If `isConnected[i][j] == 1`, union `i` and `j`. After processing all edges, count how many nodes are their own parents (`parent[i] == i`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Use DisjointSet class from Kruskal&#x27;s&#10;int findCircleNum(vector&lt;vector&lt;int&gt;&gt;&amp; isConnected) {&#10;    int n = isConnected.size();&#10;    DisjointSet ds(n);&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(isConnected[i][j] == 1) ds.unionByRank(i, j);&#10;        }&#10;    }&#10;    int cnt = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(ds.findUPar(i) == i) cnt++;&#10;    }&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>45</td>
      <td>Graph 46 Number Of Operations To Make Network Connected<br><br></b> <a href='https://leetcode.com/problems/number-of-operations-to-make-network-connected/' target='_blank'>LeetCode 1319</a></td>
      <td><b>Example 1:</b> Count Extra Edges using DSU.</td>
      <td><b>Time:</b> O(E * alpha)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If total edges < n - 1, return -1. Count extra edges while building DSU. If union fails (already connected), it's an extra edge. Number of operations to connect components is `components - 1`. If `extraEdges >= components - 1`, return `components - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int makeConnected(int n, vector&lt;vector&lt;int&gt;&gt;&amp; connections) {&#10;    if(connections.size() &lt; n - 1) return -1;&#10;    DisjointSet ds(n);&#10;    int extraEdges = 0;&#10;    for(auto&amp; it : connections) {&#10;        if(ds.findUPar(it[0]) == ds.findUPar(it[1])) {&#10;            extraEdges++;&#10;        } else {&#10;            ds.unionByRank(it[0], it[1]);&#10;        }&#10;    }&#10;    int components = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(ds.findUPar(i) == i) components++;&#10;    }&#10;    if(extraEdges &gt;= components - 1) return components - 1;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>46</td>
      <td>Graph 47 Most Stones Removed With Same Row Or Column<br><br></b> <a href='https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/' target='_blank'>LeetCode 947</a></td>
      <td><b>Example 1:</b> DSU on Rows and Columns.</td>
      <td><b>Time:</b> O(N * alpha)<br><b>Space:</b> O(Max(Row, Col))</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Treat rows and columns as nodes in DSU. Connect row `x` to column `y` for each stone. Max row and max col define the size of DSU. A column node index can be `maxRow + y + 1` to separate from row indices. The answer is `total stones - number of connected components`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeStones(vector&lt;vector&lt;int&gt;&gt;&amp; stones) {&#10;    int maxRow = 0, maxCol = 0;&#10;    for(auto&amp; it : stones) {&#10;        maxRow = max(maxRow, it[0]);&#10;        maxCol = max(maxCol, it[1]);&#10;    }&#10;    DisjointSet ds(maxRow + maxCol + 1);&#10;    unordered_set&lt;int&gt; stoneNodes;&#10;    for(auto&amp; it : stones) {&#10;        int nodeRow = it[0];&#10;        int nodeCol = it[1] + maxRow + 1;&#10;        ds.unionByRank(nodeRow, nodeCol);&#10;        stoneNodes.insert(nodeRow);&#10;        stoneNodes.insert(nodeCol);&#10;    }&#10;    int components = 0;&#10;    for(int node : stoneNodes) {&#10;        if(ds.findUPar(node) == node) components++;&#10;    }&#10;    return stones.size() - components;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>47</td>
      <td>Graph 48 Accounts Merge<br><br></b> <a href='https://leetcode.com/problems/accounts-merge/' target='_blank'>LeetCode 721</a></td>
      <td><b>Example 1:</b> Map Emails to IDs, DSU on IDs.</td>
      <td><b>Time:</b> O(N * M * log(N * M)) where N=accounts, M=max emails<br><b>Space:</b> O(N * M)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Create a DSU of size N (number of accounts). Map each email to its first seen account ID. If an email is seen again, union the current account ID with the mapped account ID. Then group emails by the ultimate parent of their account ID. Sort emails in each group and format the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;string&gt;&gt; accountsMerge(vector&lt;vector&lt;string&gt;&gt;&amp; accounts) {&#10;    int n = accounts.size();&#10;    DisjointSet ds(n);&#10;    unordered_map&lt;string, int&gt; mailNode;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 1; j &lt; accounts[i].size(); j++) {&#10;            string mail = accounts[i][j];&#10;            if(mailNode.find(mail) == mailNode.end()) {&#10;                mailNode[mail] = i;&#10;            } else {&#10;                ds.unionByRank(i, mailNode[mail]);&#10;            }&#10;        }&#10;    }&#10;    vector&lt;vector&lt;string&gt;&gt; mergedMails(n);&#10;    for(auto&amp; it : mailNode) {&#10;        string mail = it.first;&#10;        int node = ds.findUPar(it.second);&#10;        mergedMails[node].push_back(mail);&#10;    }&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(mergedMails[i].empty()) continue;&#10;        sort(mergedMails[i].begin(), mergedMails[i].end());&#10;        vector&lt;string&gt; temp;&#10;        temp.push_back(accounts[i][0]);&#10;        for(string&amp; mail : mergedMails[i]) temp.push_back(mail);&#10;        ans.push_back(temp);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>48</td>
      <td>Graph 49 Network Delay Time<br><br></b> <a href='https://leetcode.com/problems/network-delay-time/' target='_blank'>LeetCode 743</a></td>
      <td><b>Example 1:</b> Dijkstra's Algorithm.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(N + E)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Find shortest path from source node `k` to all other nodes using Dijkstra's algorithm. The answer is the maximum distance among all nodes. If any node is unreachable (distance is infinity), return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int networkDelayTime(vector&lt;vector&lt;int&gt;&gt;&amp; times, int n, int k) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; adj(n + 1);&#10;    for(auto&amp; t : times) {&#10;        adj[t[0]].push_back({t[1], t[2]});&#10;    }&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(n + 1, 1e9);&#10;    dist[k] = 0;&#10;    pq.push({0, k});&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int d = it.first, node = it.second;&#10;        if(d &gt; dist[node]) continue;&#10;        for(auto&amp; neighbor : adj[node]) {&#10;            int adjNode = neighbor.first;&#10;            int wt = neighbor.second;&#10;            if(d + wt &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + wt;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    int maxDelay = 0;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        if(dist[i] == 1e9) return -1;&#10;        maxDelay = max(maxDelay, dist[i]);&#10;    }&#10;    return maxDelay;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>49</td>
      <td>Graph 50 Find Eventual Safe States<br><br></b> <a href='https://leetcode.com/problems/find-eventual-safe-states/' target='_blank'>LeetCode 802</a></td>
      <td><b>Example 1:</b> Topological Sort using Kahn's Algorithm on reversed graph.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Reverse all edges in the graph. Terminal nodes become sources (indegree 0). Run Kahn's algorithm (BFS topological sort). Any node processed is part of a path that only leads to terminal nodes (safe node). Sort the resulting nodes.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; eventualSafeNodes(vector&lt;vector&lt;int&gt;&gt;&amp; graph) {&#10;    int V = graph.size();&#10;    vector&lt;vector&lt;int&gt;&gt; adjRev(V);&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(int i = 0; i &lt; V; i++) {&#10;        for(auto it : graph[i]) {&#10;            adjRev[it].push_back(i);&#10;            indegree[i]++;&#10;        }&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(indegree[i] == 0) q.push(i);&#10;    }&#10;    vector&lt;int&gt; safeNodes;&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        safeNodes.push_back(node);&#10;        for(auto it : adjRev[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    sort(safeNodes.begin(), safeNodes.end());&#10;    return safeNodes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>50</td>
      <td>Graph 51 Word Ladder<br><br></b> <a href='https://leetcode.com/problems/word-ladder/' target='_blank'>LeetCode 127</a></td>
      <td><b>Example 1:</b> BFS Shortest Path.</td>
      <td><b>Time:</b> O(N * L * 26) where L is word length<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue>\n#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use BFS. Insert words from `wordList` into a hash set for O(1) lookup. Push `{beginWord, 1}` to a queue and remove it from the set. Pop a word, change each character one by one to 'a'-'z'. If the new word is in the set, push `{newWord, steps+1}` and remove from set. If `newWord == endWord`, return `steps+1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int ladderLength(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;pair&lt;string, int&gt;&gt; q;&#10;    q.push({beginWord, 1});&#10;    st.erase(beginWord);&#10;    while(!q.empty()) {&#10;        string word = q.front().first;&#10;        int steps = q.front().second;&#10;        q.pop();&#10;        if(word == endWord) return steps;&#10;        for(int i = 0; i &lt; word.size(); i++) {&#10;            char original = word[i];&#10;            for(char ch = &#x27;a&#x27;; ch &lt;= &#x27;z&#x27;; ch++) {&#10;                word[i] = ch;&#10;                if(st.find(word) != st.end()) {&#10;                    st.erase(word);&#10;                    q.push({word, steps + 1});&#10;                }&#10;            }&#10;            word[i] = original;&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>51</td>
      <td>Graph 52 Word Ladder Ii<br><br></b> <a href='https://leetcode.com/problems/word-ladder-ii/' target='_blank'>LeetCode 126</a></td>
      <td><b>Example 1:</b> BFS to find shortest path map + DFS to backtrack paths.</td>
      <td><b>Time:</b> O(N * L * 26 + Paths)<br><b>Space:</b> O(N * L)</td>
      <td><code>#include <queue>\n#include <unordered_set>\n#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> First, use BFS to build a map storing the shortest distance from `beginWord` to every reachable word. Then use DFS starting from `endWord` backwards to `beginWord` to reconstruct the paths. In DFS, only traverse to words whose distance is exactly 1 less than the current word's distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">unordered_map&lt;string, int&gt; mpp;&#10;vector&lt;vector&lt;string&gt;&gt; ans;&#10;string b;&#10;void dfs(string word, vector&lt;string&gt;&amp; seq) {&#10;    if(word == b) {&#10;        vector&lt;string&gt; temp = seq;&#10;        reverse(temp.begin(), temp.end());&#10;        ans.push_back(temp);&#10;        return;&#10;    }&#10;    int steps = mpp[word];&#10;    for(int i = 0; i &lt; word.size(); i++) {&#10;        char original = word[i];&#10;        for(char c = &#x27;a&#x27;; c &lt;= &#x27;z&#x27;; c++) {&#10;            word[i] = c;&#10;            if(mpp.find(word) != mpp.end() &amp;&amp; mpp[word] == steps - 1) {&#10;                seq.push_back(word);&#10;                dfs(word, seq);&#10;                seq.pop_back();&#10;            }&#10;        }&#10;        word[i] = original;&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; findLadders(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;string&gt; q;&#10;    b = beginWord;&#10;    q.push({beginWord});&#10;    mpp[beginWord] = 1;&#10;    st.erase(beginWord);&#10;    int sz = beginWord.size();&#10;    while(!q.empty()) {&#10;        string word = q.front(); q.pop();&#10;        int steps = mpp[word];&#10;        if(word == endWord) break;&#10;        for(int i = 0; i &lt; sz; i++) {&#10;            char original = word[i];&#10;            for(char c = &#x27;a&#x27;; c &lt;= &#x27;z&#x27;; c++) {&#10;                word[i] = c;&#10;                if(st.count(word)) {&#10;                    q.push(word);&#10;                    st.erase(word);&#10;                    mpp[word] = steps + 1;&#10;                }&#10;            }&#10;            word[i] = original;&#10;        }&#10;    }&#10;    if(mpp.find(endWord) != mpp.end()) {&#10;        vector&lt;string&gt; seq;&#10;        seq.push_back(endWord);&#10;        dfs(endWord, seq);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>52</td>
      <td>Graph 53 Making A Large Island<br><br></b> <a href='https://leetcode.com/problems/making-a-large-island/' target='_blank'>LeetCode 827</a></td>
      <td><b>Example 1:</b> Disjoint Set / Union Find.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Step 1: Traverse the grid. For each `1`, union it with its `1` neighbors. Calculate the size of each component using DSU. Step 2: Traverse again. For each `0`, check its 4 neighbors. Find unique ultimate parents among neighbors, sum their sizes, and add 1 (for the flipped `0`). Keep track of the maximum size found.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestIsland(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    DisjointSet ds(n * n);&#10;    int dr[] = {-1, 0, 1, 0};&#10;    int dc[] = {0, 1, 0, -1};&#10;    for(int row = 0; row &lt; n; row++) {&#10;        for(int col = 0; col &lt; n; col++) {&#10;            if(grid[row][col] == 0) continue;&#10;            for(int ind = 0; ind &lt; 4; ind++) {&#10;                int newr = row + dr[ind], newc = col + dc[ind];&#10;                if(newr &gt;= 0 &amp;&amp; newr &lt; n &amp;&amp; newc &gt;= 0 &amp;&amp; newc &lt; n &amp;&amp; grid[newr][newc] == 1) {&#10;                    int nodeNo = row * n + col;&#10;                    int adjNodeNo = newr * n + newc;&#10;                    ds.unionByRank(nodeNo, adjNodeNo);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    int mx = 0;&#10;    for(int row = 0; row &lt; n; row++) {&#10;        for(int col = 0; col &lt; n; col++) {&#10;            if(grid[row][col] == 1) continue;&#10;            unordered_set&lt;int&gt; components;&#10;            for(int ind = 0; ind &lt; 4; ind++) {&#10;                int newr = row + dr[ind], newc = col + dc[ind];&#10;                if(newr &gt;= 0 &amp;&amp; newr &lt; n &amp;&amp; newc &gt;= 0 &amp;&amp; newc &lt; n &amp;&amp; grid[newr][newc] == 1) {&#10;                    components.insert(ds.findUPar(newr * n + newc));&#10;                }&#10;            }&#10;            int sizeTotal = 0;&#10;            for(auto it : components) sizeTotal += ds.size[it];&#10;            mx = max(mx, sizeTotal + 1);&#10;        }&#10;    }&#10;    for(int cellNo = 0; cellNo &lt; n * n; cellNo++) mx = max(mx, ds.size[ds.findUPar(cellNo)]);&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>53</td>
      <td>Graph 54 Swim In Rising Water<br><br></b> <a href='https://leetcode.com/problems/swim-in-rising-water/' target='_blank'>LeetCode 778</a></td>
      <td><b>Example 1:</b> Dijkstra's Algorithm with Max Path Edge.</td>
      <td><b>Time:</b> O(N^2 log N)<br><b>Space:</b> O(N^2)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a priority queue to always process the cell with the minimum maximum-elevation so far. `pq` stores `(max_elev_in_path, r, c)`. Push `(grid[0][0], 0, 0)`. While pq is not empty, pop the minimum. If we reach `(n-1, n-1)`, return the `max_elev`. For each neighbor, the new max elevation is `max(max_elev, grid[nr][nc])`. Push to pq if not visited.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int swimInWater(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    priority_queue&lt;pair&lt;int, pair&lt;int, int&gt;&gt;, vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt;, greater&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt;&gt; pq;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    pq.push({grid[0][0], {0, 0}});&#10;    vis[0][0] = 1;&#10;    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int t = it.first, r = it.second.first, c = it.second.second;&#10;        if(r == n - 1 &amp;&amp; c == n - 1) return t;&#10;        for(int i=0; i&lt;4; i++) {&#10;            int nr = r + dr[i], nc = c + dc[i];&#10;            if(nr &gt;= 0 &amp;&amp; nr &lt; n &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; n &amp;&amp; !vis[nr][nc]) {&#10;                vis[nr][nc] = 1;&#10;                pq.push({max(t, grid[nr][nc]), {nr, nc}});&#10;            }&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>54</td>
      <td>Graph 14 Detect Cycle In A Directed Graph<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DFS with pathVisited.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>Multiple disconnected components</td>
      <td><b>Explanation:</b> Use DFS. Maintain a `visited` array and a `pathVisited` array. Mark both as true for the current node. Recurse for adjacent nodes. If an adjacent node is `visited` AND `pathVisited`, a cycle exists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfsCheck(int node, vector&lt;int&gt; adj[], int vis[], int pathVis[]) {&#10;    vis[node] = 1;&#10;    pathVis[node] = 1;&#10;    for(auto it : adj[node]) {&#10;        if(!vis[it]) {&#10;            if(dfsCheck(it, adj, vis, pathVis)) return true;&#10;        } else if(pathVis[it]) {&#10;            return true;&#10;        }&#10;    }&#10;    pathVis[node] = 0;&#10;    return false;&#10;}&#10;bool isCyclic(int V, vector&lt;int&gt; adj[]) {&#10;    int vis[V] = {0};&#10;    int pathVis[V] = {0};&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(!vis[i]) {&#10;            if(dfsCheck(i, adj, vis, pathVis)) return true;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>55</td>
      <td>Graph 15 Topological Sort Bfs Kahn<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Indegree based BFS.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Calculate indegree for all nodes. Push all nodes with indegree 0 to a queue. While queue is not empty, pop a node, add it to result, and decrement indegree of all its adjacent nodes. If indegree becomes 0, push to queue.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    int indegree[V] = {0};&#10;    for(int i = 0; i &lt; V; i++) {&#10;        for(auto it : adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(indegree[i] == 0) q.push(i);&#10;    }&#10;    vector&lt;int&gt; topo;&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        topo.push_back(node);&#10;        for(auto it : adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>56</td>
      <td>Graph 16 Topological Sort Dfs<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DFS + Stack.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Use standard DFS. When returning from the DFS call of a node (meaning all its descendants are visited), push the node to a stack. The stack will contain the topological sort.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, int vis[], stack&lt;int&gt;&amp; st, vector&lt;int&gt; adj[]) {&#10;    vis[node] = 1;&#10;    for(auto it : adj[node]) {&#10;        if(!vis[it]) dfs(it, vis, st, adj);&#10;    }&#10;    st.push(node);&#10;}&#10;vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    int vis[V] = {0};&#10;    stack&lt;int&gt; st;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(!vis[i]) dfs(i, vis, st, adj);&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!st.empty()) {&#10;        ans.push_back(st.top());&#10;        st.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>57</td>
      <td>Graph 18 Find Whether It Is Possible To Finish All Tasks Or Not From Given Dependencies<br><br></b> <a href='https://leetcode.com/problems/course-schedule/' target='_blank'>LeetCode 207</a></td>
      <td><b>Example 1:</b> Detect cycle using Kahn's algorithm.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> This is equivalent to detecting a cycle in a directed graph. If a cycle exists, it's impossible. Use Kahn's algorithm: if the number of elements in the topological sort is not equal to `N`, then a cycle exists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canFinish(int numCourses, vector&lt;vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    vector&lt;int&gt; adj[numCourses];&#10;    for(auto it : prerequisites) {&#10;        adj[it[1]].push_back(it[0]);&#10;    }&#10;    int indegree[numCourses] = {0};&#10;    for(int i = 0; i &lt; numCourses; i++) {&#10;        for(auto it : adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i = 0; i &lt; numCourses; i++) {&#10;        if(indegree[i] == 0) q.push(i);&#10;    }&#10;    int cnt = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        cnt++;&#10;        for(auto it : adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return cnt == numCourses;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>58</td>
      <td>Graph 19 Find The Number Of Islands<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DFS or BFS.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) worst case stack</td>
      <td>-</td>
      <td>Empty grid</td>
      <td><b>Explanation:</b> Traverse the grid. When a '1' is found, increment island count and use DFS/BFS to mark all its 8-connected neighbors as '0' (or visited) to avoid recounting.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int r, int c, vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    grid[r][c] = &#x27;0&#x27;;&#10;    for(int delrow = -1; delrow &lt;= 1; delrow++) {&#10;        for(int delcol = -1; delcol &lt;= 1; delcol++) {&#10;            int nrow = r + delrow;&#10;            int ncol = c + delcol;&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; grid[nrow][ncol] == &#x27;1&#x27;) {&#10;                dfs(nrow, ncol, grid);&#10;            }&#10;        }&#10;    }&#10;}&#10;int numIslands(vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    if(n == 0) return 0;&#10;    int m = grid[0].size();&#10;    int count = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(i, j, grid);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>59</td>
      <td>Graph 20 Alien Dictionary<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/alien-dictionary/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Topological Sort on Characters.</td>
      <td><b>Time:</b> O(N * length of words + K)<br><b>Space:</b> O(K)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Compare adjacent words. The first mismatching character defines a directed edge `char1 -> char2`. Create an adjacency list of these edges. Then perform a topological sort to get the valid character order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string findOrder(string dict[], int N, int K) {&#10;    vector&lt;int&gt; adj[K];&#10;    for(int i = 0; i &lt; N - 1; i++) {&#10;        string s1 = dict[i];&#10;        string s2 = dict[i+1];&#10;        int len = min(s1.length(), s2.length());&#10;        for(int ptr = 0; ptr &lt; len; ptr++) {&#10;            if(s1[ptr] != s2[ptr]) {&#10;                adj[s1[ptr] - &#x27;a&#x27;].push_back(s2[ptr] - &#x27;a&#x27;);&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    int indegree[K] = {0};&#10;    for(int i = 0; i &lt; K; i++) {&#10;        for(auto it : adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i = 0; i &lt; K; i++) {&#10;        if(indegree[i] == 0) q.push(i);&#10;    }&#10;    string topo = &quot;&quot;;&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        topo += (char)(node + &#x27;a&#x27;);&#10;        for(auto it : adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>60</td>
      <td>Graph 21 Kruskals Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Disjoint Set Union.</td>
      <td><b>Time:</b> O(E log E)<br><b>Space:</b> O(V + E)</td>
      <td>Disjoint Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort all edges by weight. Iterate through sorted edges, if the two vertices do not belong to the same set (using Disjoint Set Union `findParent`), add the edge to MST and `union` the two sets.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;    vector&lt;int&gt; parent, size;&#10;public:&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt; edges;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        for(auto it : adj[i]) {&#10;            int adjNode = it[0], wt = it[1];&#10;            edges.push_back({wt, {i, adjNode}});&#10;        }&#10;    }&#10;    sort(edges.begin(), edges.end());&#10;    DisjointSet ds(V);&#10;    int mstWt = 0;&#10;    for(auto it : edges) {&#10;        int wt = it.first, u = it.second.first, v = it.second.second;&#10;        if(ds.findUPar(u) != ds.findUPar(v)) {&#10;            mstWt += wt;&#10;            ds.unionBySize(u, v);&#10;        }&#10;    }&#10;    return mstWt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>61</td>
      <td>Graph 22 Dijkstra Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Priority Queue / Min Heap.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V + E)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a min-heap to always pick the node with the minimum distance. Relax its adjacent edges. If `dist[node] + weight < dist[adjNode]`, update distance and push to priority queue.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int dis = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int edgeWeight = it[1];&#10;            int adjNode = it[0];&#10;            if(dis + edgeWeight &lt; dist[adjNode]) {&#10;                dist[adjNode] = dis + edgeWeight;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>62</td>
      <td>Graph 23 Bipartite Graph<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/bipartite-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Graph Coloring (BFS).</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>Multiple disconnected components</td>
      <td><b>Explanation:</b> Try to color the graph using 2 colors. Use BFS/DFS. For every unvisited node, color it 0. For its neighbors, color them opposite (1). If a neighbor is already colored with the SAME color, it's not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool check(int start, int V, vector&lt;int&gt; adj[], int color[]) {&#10;    queue&lt;int&gt; q;&#10;    q.push(start);&#10;    color[start] = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        for(auto it : adj[node]) {&#10;            if(color[it] == -1) {&#10;                color[it] = !color[node];&#10;                q.push(it);&#10;            } else if(color[it] == color[node]) {&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;bool isBipartite(int V, vector&lt;int&gt;adj[]) {&#10;    int color[V];&#10;    for(int i = 0; i &lt; V; i++) color[i] = -1;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(color[i] == -1) {&#10;            if(check(i, V, adj, color) == false) return false;&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>63</td>
      <td>Graph 15 Find Bridge In A Graph<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Tarjan's Algorithm / DFS.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Remove the given edge `(c, d)` from the graph. Then run a DFS/BFS from `c`. If `d` is not reachable from `c`, then `(c, d)` was a bridge.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt; adj[], vector&lt;bool&gt;&amp; vis, int c, int d) {&#10;    vis[node] = true;&#10;    for(int nbr : adj[node]) {&#10;        if((node == c &amp;&amp; nbr == d) || (node == d &amp;&amp; nbr == c)) continue;&#10;        if(!vis[nbr]) dfs(nbr, adj, vis, c, d);&#10;    }&#10;}&#10;int isBridge(int V, vector&lt;int&gt; adj[], int c, int d) {&#10;    vector&lt;bool&gt; vis(V, false);&#10;    dfs(c, adj, vis, c, d);&#10;    if(!vis[d]) return 1;&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>64</td>
      <td>Graph 16 Strongly Connected Components Kosaraju<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Kosaraju's Algorithm.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 1. Perform DFS and push nodes to stack upon finish (topological sort order). 2. Reverse all edges of the graph. 3. Pop nodes from stack and perform DFS on the reversed graph. Each DFS call gives one Strongly Connected Component.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs1(int node, vector&lt;vector&lt;int&gt;&gt;&amp; adj, vector&lt;bool&gt;&amp; vis, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = true;&#10;    for(int nbr : adj[node]) if(!vis[nbr]) dfs1(nbr, adj, vis, st);&#10;    st.push(node);&#10;}&#10;void dfs2(int node, vector&lt;vector&lt;int&gt;&gt;&amp; revAdj, vector&lt;bool&gt;&amp; vis) {&#10;    vis[node] = true;&#10;    for(int nbr : revAdj[node]) if(!vis[nbr]) dfs2(nbr, revAdj, vis);&#10;}&#10;int kosaraju(int V, vector&lt;vector&lt;int&gt;&gt;&amp; adj) {&#10;    vector&lt;bool&gt; vis(V, false);&#10;    stack&lt;int&gt; st;&#10;    for(int i = 0; i &lt; V; i++) if(!vis[i]) dfs1(i, adj, vis, st);&#10;    vector&lt;vector&lt;int&gt;&gt; revAdj(V);&#10;    for(int i = 0; i &lt; V; i++) {&#10;        vis[i] = false;&#10;        for(int nbr : adj[i]) revAdj[nbr].push_back(i);&#10;    }&#10;    int scc = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top(); st.pop();&#10;        if(!vis[node]) {&#10;            dfs2(node, revAdj, vis);&#10;            scc++;&#10;        }&#10;    }&#10;    return scc;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>65</td>
      <td>Graph 17 Bipartite Graph<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/bipartite-graph/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Graph Coloring (BFS).</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>Disconnected components</td>
      <td><b>Explanation:</b> Use BFS to color the graph with 2 colors (0 and 1). Start with a node, color it 0. All its neighbors must be colored 1, their neighbors 0, and so on. If we ever find an adjacent node with the same color, the graph is not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkBipartite(int start, vector&lt;int&gt; adj[], vector&lt;int&gt;&amp; color) {&#10;    queue&lt;int&gt; q;&#10;    q.push(start);&#10;    color[start] = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        for(int nbr : adj[node]) {&#10;            if(color[nbr] == -1) {&#10;                color[nbr] = 1 - color[node];&#10;                q.push(nbr);&#10;            } else if(color[nbr] == color[node]) return false;&#10;        }&#10;    }&#10;    return true;&#10;}&#10;bool isBipartite(int V, vector&lt;int&gt;adj[]){&#10;    vector&lt;int&gt; color(V, -1);&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(color[i] == -1) {&#10;            if(!checkBipartite(i, adj, color)) return false;&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>66</td>
      <td>Graph 18 Word Ladder<br><br></b> <a href='https://leetcode.com/problems/word-ladder/' target='_blank'>LeetCode 127</a></td>
      <td><b>Example 1:</b> BFS level order.</td>
      <td><b>Time:</b> O(N * M * 26)<br><b>Space:</b> O(N * M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use BFS to find the shortest path. Put the `beginWord` in a queue. For each word popped from the queue, try changing every character to all 26 lowercase letters. If the new word is in the dictionary, push it to the queue with level + 1 and remove it from dictionary to avoid cycles.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int ladderLength(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;pair&lt;string, int&gt;&gt; q;&#10;    q.push({beginWord, 1});&#10;    if(st.find(beginWord) != st.end()) st.erase(beginWord);&#10;    while(!q.empty()) {&#10;        string word = q.front().first;&#10;        int steps = q.front().second;&#10;        q.pop();&#10;        if(word == endWord) return steps;&#10;        for(int i = 0; i &lt; word.length(); i++) {&#10;            char orig = word[i];&#10;            for(char c = &#x27;a&#x27;; c &lt;= &#x27;z&#x27;; c++) {&#10;                word[i] = c;&#10;                if(st.find(word) != st.end()) {&#10;                    st.erase(word);&#10;                    q.push({word, steps + 1});&#10;                }&#10;            }&#10;            word[i] = orig;&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>67</td>
      <td>Graph 19 Dijkstras Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Priority Queue.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Initialize distances to infinity, and source distance to 0. Use a Min Heap (priority queue) to store `{dist, vertex}`. Pop the vertex with min distance, and relax its neighbors. If a shorter path is found to a neighbor, push it to the queue.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int v = it[0];&#10;            int wt = it[1];&#10;            if(d + wt &lt; dist[v]) {&#10;                dist[v] = d + wt;&#10;                pq.push({dist[v], v});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>68</td>
      <td>Graph 20 Alien Dictionary V2<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/alien-dictionary/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Topological Sort.</td>
      <td><b>Time:</b> O(N * L + K)<br><b>Space:</b> O(K)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Compare adjacent words in the sorted dictionary. The first differing character creates a directed edge `char1 -> char2` indicating `char1` comes before `char2`. Build a directed graph and perform Topological Sorting to get the order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string findOrder(string dict[], int N, int K) {&#10;    vector&lt;int&gt; adj[K];&#10;    for(int i = 0; i &lt; N - 1; i++) {&#10;        string s1 = dict[i], s2 = dict[i+1];&#10;        int len = min(s1.length(), s2.length());&#10;        for(int j = 0; j &lt; len; j++) {&#10;            if(s1[j] != s2[j]) {&#10;                adj[s1[j] - &#x27;a&#x27;].push_back(s2[j] - &#x27;a&#x27;);&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    vector&lt;int&gt; inDegree(K, 0);&#10;    for(int i = 0; i &lt; K; i++) {&#10;        for(int nbr : adj[i]) inDegree[nbr]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i = 0; i &lt; K; i++) if(inDegree[i] == 0) q.push(i);&#10;    string ans = &quot;&quot;;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        ans += (char)(node + &#x27;a&#x27;);&#10;        for(int nbr : adj[node]) {&#10;            inDegree[nbr]--;&#10;            if(inDegree[nbr] == 0) q.push(nbr);&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>69</td>
      <td>Graph 21 Kruskals Algorithm V2<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Disjoint Set + Sort edges.</td>
      <td><b>Time:</b> O(E log E)<br><b>Space:</b> O(V + E)</td>
      <td>Disjoint Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort all edges by weight. Use a Disjoint Set (Union-Find) to maintain components. Iterate through sorted edges, and if adding the edge doesn't form a cycle (i.e. nodes belong to different sets), add its weight to MST and union the sets.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;    vector&lt;int&gt; parent, size;&#10;public:&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u), ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt; edges;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        for(auto it : adj[i]) {&#10;            int adjNode = it[0], wt = it[1];&#10;            edges.push_back({wt, {i, adjNode}});&#10;        }&#10;    }&#10;    DisjointSet ds(V);&#10;    sort(edges.begin(), edges.end());&#10;    int mstWt = 0;&#10;    for(auto it : edges) {&#10;        int wt = it.first, u = it.second.first, v = it.second.second;&#10;        if(ds.findUPar(u) != ds.findUPar(v)) {&#10;            mstWt += wt;&#10;            ds.unionBySize(u, v);&#10;        }&#10;    }&#10;    return mstWt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>70</td>
      <td>Graph 22 Number Of Islands<br><br></b> <a href='https://leetcode.com/problems/number-of-islands/' target='_blank'>LeetCode 200</a></td>
      <td><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(M * N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through each cell. When a '1' is found, increment the island count and start a DFS/BFS to mark all connected '1's as '0' (visited).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(vector&lt;vector&lt;char&gt;&gt;&amp; grid, int r, int c) {&#10;    if(r &lt; 0 || r &gt;= grid.size() || c &lt; 0 || c &gt;= grid[0].size() || grid[r][c] == &#x27;0&#x27;) return;&#10;    grid[r][c] = &#x27;0&#x27;;&#10;    dfs(grid, r - 1, c);&#10;    dfs(grid, r + 1, c);&#10;    dfs(grid, r, c - 1);&#10;    dfs(grid, r, c + 1);&#10;}&#10;int numIslands(vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(grid, i, j);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>71</td>
      <td>Graph 23 Minimum Spanning Tree<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Prim's Algorithm.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V + E)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Min Heap to store `(weight, node)`. Start from node 0. Pop min edge. If node is unvisited, add weight to sum, mark visited, and push its unvisited neighbors to the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;bool&gt; vis(V, false);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int wt = it.first, node = it.second;&#10;        if(vis[node]) continue;&#10;        vis[node] = true;&#10;        sum += wt;&#10;        for(auto i : adj[node]) {&#10;            int adjNode = i[0], edW = i[1];&#10;            if(!vis[adjNode]) pq.push({edW, adjNode});&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
