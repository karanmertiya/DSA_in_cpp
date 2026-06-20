// Time Complexity: O(K) where K is number of valid permutations
// Space Complexity: O(N)
// Explanation: Use an array to track visited numbers. Iterate from index 1 to n. For the current index, try placing an unvisited number. Check if the condition `(num % idx == 0 || idx % num == 0)` is met. If so, mark as visited, recurse to `idx + 1`, then backtrack.

int countArrangement(int n) {
    int count = 0;
    vector<int> visited(n + 1, 0);
    function<void(int)> solve = [&](int idx) {
        if(idx > n) {
            count++;
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && (i % idx == 0 || idx % i == 0)) {
                visited[i] = 1;
                solve(idx + 1);
                visited[i] = 0;
            }
        }
    };
    solve(1);
    return count;
}

