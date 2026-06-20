// Time Complexity: O(N * L) where L is max length of string
// Space Complexity: O(L)
// Explanation: Start with `res = '1'`. For `n-1` times, iterate through `res` and count consecutive identical characters. Append the count and the character to a new string. Replace `res` with the new string.

string countAndSay(int n) {
    if(n == 1) return "1";
    string s = "1";
    for(int i = 2; i <= n; i++) {
        string temp = "";
        int count = 1;
        for(int j = 1; j < s.length(); j++) {
            if(s[j] == s[j - 1]) count++;
            else {
                temp += to_string(count) + s[j - 1];
                count = 1;
            }
        }
        temp += to_string(count) + s.back();
        s = temp;
    }
    return s;
}

