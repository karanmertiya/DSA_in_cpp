// Time Complexity: O(100000 * N)
// Space Complexity: O(100000)
// Explanation: Since each multiplication is 1 step, we can use BFS. The 'nodes' are values from 0 to 99999. Use an array `dist` initialized to infinity. Push `start` to queue. For each popped node, multiply by all array elements `% 100000`. If we find a shorter path, push to queue.

int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end) return 0;
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;
    while(!q.empty()) {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        for(int it : arr) {
            int num = (node * it) % mod;
            if(steps + 1 < dist[num]) {
                dist[num] = steps + 1;
                if(num == end) return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}

