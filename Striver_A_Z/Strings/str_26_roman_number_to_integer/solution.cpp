// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Map each Roman numeral to its integer value. Iterate from right to left. If a character is smaller than its right character, subtract its value, else add it.

int romanToDecimal(string &str) {
    unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0, n = str.length();
    for(int i = 0; i < n; i++) {
        if(i + 1 < n && m[str[i]] < m[str[i+1]]) ans -= m[str[i]];
        else ans += m[str[i]];
    }
    return ans;
}

