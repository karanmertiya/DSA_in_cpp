// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
vector<int> leaders(int a[], int n){
    vector<int> ans;
    int maxi = a[n - 1];
    ans.push_back(maxi);
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= maxi) {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(N) for output
// Explanation: Optimal: Traverse the array from right to left. Keep track of the maximum element seen so far. If the current element is greater than or equal to the max, it's a leader. Reverse the collected leaders at the end.

vector<int> leaders(int a[], int n){
    vector<int> ans;
    int maxi = a[n - 1];
    ans.push_back(maxi);
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] >= maxi) {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

