// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Maintain the prefix sum. If the current prefix sum is 0, or if it has been seen before (stored in a Hash Set), then a subarray with 0 sum exists.

bool subArrayExists(int arr[], int n) {
    unordered_set<int> s;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0 || s.find(sum) != s.end()) return true;
        s.insert(sum);
    }
    return false;
}

