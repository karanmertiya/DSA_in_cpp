// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a Hash Map to store the frequency of prefix XORs. For each element, current XOR `xr ^= A[i]`. We need `xr ^ B`. If it exists in map, add its frequency to count.

int solve(vector<int> &A, int B) {
    unordered_map<int, int> mpp;
    int xr = 0, count = 0;
    mpp[xr]++;
    for(int i=0; i<A.size(); i++) {
        xr ^= A[i];
        int x = xr ^ B;
        if(mpp.find(x) != mpp.end()) count += mpp[x];
        mpp[xr]++;
    }
    return count;
}

