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
  </tbody>
</table>
