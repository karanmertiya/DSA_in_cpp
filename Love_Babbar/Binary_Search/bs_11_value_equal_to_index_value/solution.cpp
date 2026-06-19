// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Iterate through the array. If the value at `i` is equal to `i + 1`, append it to the result array.

vector<int> valueEqualToIndex(int arr[], int n) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(arr[i] == i + 1) ans.push_back(arr[i]);
    }
    return ans;
}

