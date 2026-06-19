// Time Complexity: O(N * max_len)
// Space Complexity: O(max_len)
// Explanation: Start with "1". For `n-1` times, generate the next string by counting consecutive identical characters and appending `count` followed by the `character`.

string countAndSay(int n) {
    if(n == 1) return "1";
    string s = countAndSay(n - 1);
    string res = "";
    int count = 1;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] == s[i-1]) count++;
        else {
            res += to_string(count) + s[i-1];
            count = 1;
        }
    }
    res += to_string(count) + s.back();
    return res;
}

