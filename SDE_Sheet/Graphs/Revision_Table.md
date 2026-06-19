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
      <td rowspan="1">1</td>
      <td rowspan="1">Graph 01 Number Of Islands<br><br></b> <a href='https://leetcode.com/problems/number-of-islands/' target='_blank'>LeetCode 200</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]], Output: 3</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Constraint)</td>
      <td>-</td>
      <td><b>In-place Visited Check:</b> Sinking the island by changing '1' to '0' avoids needing a separate `visited` matrix.</td>
      <td><b>Explanation:</b> Iterate through the grid. When a '1' is found, increment island count and use DFS to sink the island (turn connected '1's to '0's).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid, int i, int j) {&#10;    if(i &lt; 0 || i &gt;= grid.size() || j &lt; 0 || j &gt;= grid[0].size() || grid[i][j] == &#x27;0&#x27;) return;&#10;    grid[i][j] = &#x27;0&#x27;; // Sink&#10;    dfs(grid, i + 1, j);&#10;    dfs(grid, i - 1, j);&#10;    dfs(grid, i, j + 1);&#10;    dfs(grid, i, j - 1);&#10;}&#10;int numIslands(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(grid, i, j);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Graph 02 Course Schedule<br><br></b> <a href='https://leetcode.com/problems/course-schedule/' target='_blank'>LeetCode 207</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: numCourses = 2, prerequisites = [[1,0]], Output: true</td>
      <td><b>Time:</b> O(V + E) (Constraint)<br><b>Space:</b> O(V + E)</td>
      <td><code>std::queue</code></td>
      <td><b>Graph Building:</b> Convert `prerequisites` edge list into an Adjacency List for fast neighbor lookups.</td>
      <td><b>Explanation:</b> Kahn's Algorithm (BFS). Count in-degrees. Add courses with 0 in-degree to queue. Process queue, reducing in-degrees of neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;bool canFinish(int numCourses, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; adj(numCourses);&#10;    std::vector&lt;int&gt; indegree(numCourses, 0);&#10;    for (auto&amp; pre : prerequisites) {&#10;        adj[pre[1]].push_back(pre[0]);&#10;        indegree[pre[0]]++;&#10;    }&#10;    std::queue&lt;int&gt; q;&#10;    for (int i = 0; i &lt; numCourses; i++) {&#10;        if (indegree[i] == 0) q.push(i);&#10;    }&#10;    int count = 0;&#10;    while (!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        count++;&#10;        for (int neighbor : adj[node]) {&#10;            indegree[neighbor]--;&#10;            if (indegree[neighbor] == 0) q.push(neighbor);&#10;        }&#10;    }&#10;    return count == numCourses;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Graph 03 Rotting Oranges<br><br></b> <a href='https://leetcode.com/problems/rotting-oranges/' target='_blank'>LeetCode 994</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: grid = [[2,1,1],[1,1,0],[0,1,1]], Output: 4</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(M * N)</td>
      <td><code>std::queue</code></td>
      <td><b>Unreachable Oranges:</b> Track total fresh oranges initially. If remaining fresh > 0 after BFS, return -1.</td>
      <td><b>Explanation:</b> Multi-source BFS. Put all initially rotten oranges in queue. Process level by level.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;int orangesRotting(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; grid) {&#10;    std::queue&lt;std::pair&lt;int, int&gt;&gt; q;&#10;    int fresh = 0, time = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == 2) q.push({i, j});&#10;            else if(grid[i][j] == 1) fresh++;&#10;        }&#10;    }&#10;    std::vector&lt;std::pair&lt;int, int&gt;&gt; dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};&#10;    while(!q.empty() &amp;&amp; fresh &gt; 0) {&#10;        int sz = q.size();&#10;        while(sz--) {&#10;            auto [r, c] = q.front(); q.pop();&#10;            for(auto&amp; d : dirs) {&#10;                int nr = r + d.first, nc = c + d.second;&#10;                if(nr &gt;= 0 &amp;&amp; nr &lt; grid.size() &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; grid[0].size() &amp;&amp; grid[nr][nc] == 1) {&#10;                    grid[nr][nc] = 2;&#10;                    q.push({nr, nc});&#10;                    fresh--;&#10;                }&#10;            }&#10;        }&#10;        time++;&#10;    }&#10;    return fresh == 0 ? time : -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Graph 04 Bipartite Graph<br><br></b> <a href='https://leetcode.com/problems/is-graph-bipartite/' target='_blank'>LeetCode 785</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]], Output: false</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><code>std::queue</code></td>
      <td><b>Disconnected Graph:</b> Must loop over all nodes `0` to `V-1` to ensure every disconnected component is checked.</td>
      <td><b>Explanation:</b> BFS/DFS coloring approach. Color adjacent nodes with alternate colors (0 and 1). If an adjacent node has the SAME color, it's not bipartite.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;bool isBipartite(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; graph) {&#10;    int n = graph.size();&#10;    std::vector&lt;int&gt; color(n, -1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(color[i] != -1) continue;&#10;        std::queue&lt;int&gt; q;&#10;        q.push(i);&#10;        color[i] = 0;&#10;        while(!q.empty()) {&#10;            int node = q.front(); q.pop();&#10;            for(int neighbor : graph[node]) {&#10;                if(color[neighbor] == -1) {&#10;                    color[neighbor] = !color[node];&#10;                    q.push(neighbor);&#10;                } else if(color[neighbor] == color[node]) {&#10;                    return false;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Graph 06 Dijkstras Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Source = 0, Output: distances array.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td><code>#include &lt;queue&gt;</code></td>
      <td><b>Disconnected graph:</b> Distances remain infinity.</td>
      <td><b>Explanation:</b> Min-heap (priority queue) to repeatedly extract the node with the minimum distance and relax its neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int adjNode = it[0], weight = it[1];&#10;            if(d + weight &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + weight;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Graph 07 Topological Sort<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: V = 4, adj = [[], [0], [0], [0]], Output: valid topological sort.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td><code>#include &lt;queue&gt;</code></td>
      <td><b>Cycles:</b> If cycle exists, result will not contain all V elements.</td>
      <td><b>Explanation:</b> Kahn's Algorithm (BFS) using in-degrees. Add nodes with 0 in-degree to a queue. Pop, append to result, and decrement in-degrees of neighbors.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(int i=0; i&lt;V; ++i) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; ++i) if(indegree[i] == 0) q.push(i);&#10;    vector&lt;int&gt; topo;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo.push_back(node);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Graph 08 Number Of Islands<br><br></b> <a href='https://leetcode.com/problems/number-of-islands/' target='_blank'>LeetCode 200</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: grid=[['1','1','0','0','0'],...], Output: 1</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) auxiliary</td>
      <td>-</td>
      <td><b>Empty Grid:</b> Returns 0.</td>
      <td><b>Explanation:</b> Traverse grid. Whenever a '1' is found, increment counter and trigger BFS/DFS to sink the island (mark '0').<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(vector&lt;vector&lt;char&gt;&gt;&amp; grid, int r, int c) {&#10;    if(r&lt;0 || c&lt;0 || r&gt;=grid.size() || c&gt;=grid[0].size() || grid[r][c] == &#x27;0&#x27;) return;&#10;    grid[r][c] = &#x27;0&#x27;;&#10;    dfs(grid, r+1, c); dfs(grid, r-1, c); dfs(grid, r, c+1); dfs(grid, r, c-1);&#10;}&#10;int numIslands(vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i=0; i&lt;grid.size(); i++) {&#10;        for(int j=0; j&lt;grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) { count++; dfs(grid, i, j); }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Graph 09 Course Schedule<br><br></b> <a href='https://leetcode.com/problems/course-schedule/' target='_blank'>LeetCode 207</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: numCourses = 2, prerequisites = [[1,0]], Output: true</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>-</td>
      <td><b>Multiple components:</b> Still works because we enqueue all 0-indegree nodes.</td>
      <td><b>Explanation:</b> Kahn's BFS or DFS cycle detection. Here Kahn's BFS is used. If topological sort contains all V vertices, then true.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canFinish(int V, vector&lt;vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    vector&lt;vector&lt;int&gt;&gt; adj(V);&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(auto it: prerequisites) {&#10;        adj[it[1]].push_back(it[0]);&#10;        indegree[it[0]]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; i++) if(indegree[i] == 0) q.push(i);&#10;    int count = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop(); count++;&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return count == V;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
