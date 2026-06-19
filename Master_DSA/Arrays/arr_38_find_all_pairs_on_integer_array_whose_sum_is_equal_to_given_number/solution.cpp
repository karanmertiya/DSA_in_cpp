// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a hash map to store frequencies. For each element `num`, check if `K - num` exists in the map. If so, add its frequency to the count. Then increment the frequency of `num` in the map.

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

