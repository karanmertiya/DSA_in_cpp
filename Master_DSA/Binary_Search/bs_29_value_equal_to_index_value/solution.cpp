// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
vector<int> valueEqualToIndex(int arr[], int n) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(arr[i] == i + 1) ans.push_back(arr[i]);
    }
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Iterate through the array. If the value at `i` is equal to `i + 1`, append it to the result array.

vector<int> valueEqualToIndex(int arr[], int n) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(arr[i] == i + 1) ans.push_back(arr[i]);
    }
    return ans;
}

