// Time Complexity: O(N + Q)
// Space Complexity: O(N)
// Explanation: Create a prefix XOR array. Query answer for `[L, R]` is `prefix[R] ^ prefix[L-1]`. If `L == 0`, answer is `prefix[R]`.

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> pref(arr.size());
    pref[0] = arr[0];
    for(int i=1; i<arr.size(); i++) pref[i] = pref[i-1] ^ arr[i];
    vector<int> ans;
    for(auto q : queries) {
        if(q[0] == 0) ans.push_back(pref[q[1]]);
        else ans.push_back(pref[q[1]] ^ pref[q[0]-1]);
    }
    return ans;
}

