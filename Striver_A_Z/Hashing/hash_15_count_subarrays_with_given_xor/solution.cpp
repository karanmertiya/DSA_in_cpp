// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Maintain prefix XOR. Use hash map to store prefix XOR frequencies. If current XOR is `xr`, we need a previous XOR `xr ^ B`. Add its frequency to count. Insert `xr` to map.

int solve(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int xr = 0, count = 0;
    for(int i = 0; i < A.size(); i++) {
        xr ^= A[i];
        if(xr == B) count++;
        if(m.find(xr ^ B) != m.end()) {
            count += m[xr ^ B];
        }
        m[xr]++;
    }
    return count;
}

