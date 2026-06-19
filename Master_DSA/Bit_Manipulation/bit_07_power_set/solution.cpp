// Time Complexity: O(2^N * N)
// Space Complexity: O(2^N * N)
// Explanation: Iterate from 1 to `2^N - 1`. For each number, treat its binary representation as a mask to pick characters from the string. Sort the resulting list of subsequences.

vector<string> AllPossibleStrings(string s){
    int n = s.length();
    vector<string> ans;
    for(int i = 1; i < (1 << n); i++) {
        string sub = "";
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) sub += s[j];
        }
        ans.push_back(sub);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

