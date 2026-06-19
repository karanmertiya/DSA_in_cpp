// Time Complexity: O(N * 2^N)
// Space Complexity: O(N * 2^N)
// Explanation: Iterate from 1 to `(1 << n) - 1`. For each number, its binary representation indicates which characters of the string to include. Example: 011 means include 1st and 2nd char.

vector<string> AllPossibleStrings(string s){
    int n = s.length();
    vector<string> res;
    for(int i = 1; i < (1 << n); i++) {
        string sub = "";
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) sub += s[j];
        }
        res.push_back(sub);
    }
    sort(res.begin(), res.end());
    return res;
}

