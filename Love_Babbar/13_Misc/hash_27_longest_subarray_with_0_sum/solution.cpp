// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Optimal: Maintain the prefix sum and a hash map storing the first occurrence index of each prefix sum. If sum is 0, length is `i+1`. If sum is in the map, length is `i - map[sum]`. Update max length.

int maxLen(vector<int>& A, int n) {
    unordered_map<int, int> m;
    int maxi = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
        if(sum == 0) maxi = i + 1;
        else {
            if(m.find(sum) != m.end()) {
                maxi = max(maxi, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
    }
    return maxi;
}

