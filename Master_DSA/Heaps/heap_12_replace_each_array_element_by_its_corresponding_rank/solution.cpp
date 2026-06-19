// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Create a copy of array, sort it, and remove duplicates. Use a hash map to map each unique value to its rank. Replace elements in original array using map.

vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> st(arr.begin(), arr.end());
    unordered_map<int, int> mpp;
    int rank = 1;
    for(int num : st) mpp[num] = rank++;
    vector<int> ans;
    for(int num : arr) ans.push_back(mpp[num]);
    return ans;
}

