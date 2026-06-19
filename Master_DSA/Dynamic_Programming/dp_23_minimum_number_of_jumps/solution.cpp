// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a greedy approach. Maintain `maxReach`, `step`, and `jump`. If `i == n - 1`, return `jump`. If `arr[0] == 0`, return -1. Otherwise, decrement `step`. If `step == 0`, `jump++`, `step = maxReach - i`. If `i >= maxReach`, it's impossible.

int minJumps(int arr[], int n){
    if(n <= 1) return 0;
    if(arr[0] == 0) return -1;
    int maxReach = arr[0], step = arr[0], jump = 1;
    for(int i = 1; i < n; i++) {
        if(i == n - 1) return jump;
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if(step == 0) {
            jump++;
            if(i >= maxReach) return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

