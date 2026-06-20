// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Since `pref[i] = pref[i-1] ^ arr[i]`, we can find `arr[i]` by doing `pref[i-1] ^ pref[i]`. `arr[0] = pref[0]`.

vector<int> findArray(vector<int>& pref) {
    vector<int> arr(pref.size());
    arr[0] = pref[0];
    for(int i=1; i<pref.size(); i++) {
        arr[i] = pref[i-1] ^ pref[i];
    }
    return arr;
}

