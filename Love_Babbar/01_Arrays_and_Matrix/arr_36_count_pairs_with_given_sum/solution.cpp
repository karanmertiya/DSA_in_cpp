// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Optimal: Use a hash map to store the frequencies of the elements seen so far. For each element `x`, check if `K - x` is in the hash map. If it is, add its frequency to the `count`. Finally, increment the frequency of `x` in the hash map.

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> m;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(m.find(k - arr[i]) != m.end()) {
            count += m[k - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}

