// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Maintain `maxReach`, `steps`, and `jumps`. At each step `i`, `maxReach = max(maxReach, i + arr[i])`. Decrement `steps`. If `steps == 0`, `jumps++` and `steps = maxReach - i`. If `i >= maxReach`, return -1.

int minJumps(int arr[], int n) {
    if(n <= 1) return 0;
    if(arr[0] == 0) return -1;
    int maxReach = arr[0], steps = arr[0], jumps = 1;
    for(int i = 1; i < n; i++) {
        if(i == n - 1) return jumps;
        maxReach = max(maxReach, i + arr[i]);
        steps--;
        if(steps == 0) {
            jumps++;
            if(i >= maxReach) return -1;
            steps = maxReach - i;
        }
    }
    return -1;
}

