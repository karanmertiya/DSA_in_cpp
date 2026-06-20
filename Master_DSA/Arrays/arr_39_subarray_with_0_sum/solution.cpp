// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
bool subArrayExists(int arr[], int n) {
    unordered_set<int> sumSet;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0 || sumSet.find(sum) != sumSet.end()) return true;
        sumSet.insert(sum);
    }
    return false;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Optimal: Iterate through the array and calculate the prefix sum. If the prefix sum is 0 or it already exists in a hash set, it means a subarray with sum 0 exists.

bool subArrayExists(int arr[], int n) {
    unordered_set<int> sumSet;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0 || sumSet.find(sum) != sumSet.end()) return true;
        sumSet.insert(sum);
    }
    return false;
}

