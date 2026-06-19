// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Maintain the prefix XOR. Use a hash map to store the frequency of each prefix XOR. If current prefix XOR is `xr`, we want to find if there was a previous prefix XOR `xr ^ B`. If so, add its frequency to the count. Then add the current `xr` to the map.

int solve(vector<int> &A, int B) {
    unordered_map<int, int> freq;
    int count = 0, xr = 0;
    for(int i = 0; i < A.size(); i++) {
        xr = xr ^ A[i];
        if(xr == B) count++;
        if(freq.find(xr ^ B) != freq.end()) {
            count += freq[xr ^ B];
        }
        freq[xr]++;
    }
    return count;
}

