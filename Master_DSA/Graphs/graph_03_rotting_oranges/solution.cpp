// Time Complexity: O(M * N)
// Space Complexity: O(M * N)
// Explanation: Multi-source BFS. Put all initially rotten oranges in queue. Process level by level.

#include <vector>
#include <queue>
int orangesRotting(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> q;
    int fresh = 0, time = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 2) q.push({i, j});
            else if(grid[i][j] == 1) fresh++;
        }
    }
    std::vector<std::pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty() && fresh > 0) {
        int sz = q.size();
        while(sz--) {
            auto [r, c] = q.front(); q.pop();
            for(auto& d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
        }
        time++;
    }
    return fresh == 0 ? time : -1;
}

