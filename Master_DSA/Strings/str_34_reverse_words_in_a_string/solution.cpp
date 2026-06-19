// Time Complexity: O(N)
// Space Complexity: O(N) for output string
// Explanation: Iterate from right to left. Find the end of a word, then the start of a word. Extract the word and append it to the result string along with a space. Finally, remove the trailing space.

string reverseWords(string s) {
    string result = "";
    int i = s.length() - 1;
    while(i >= 0) {
        while(i >= 0 && s[i] == ' ') i--;
        if(i < 0) break;
        int j = i;
        while(i >= 0 && s[i] != ' ') i--;
        result += s.substr(i + 1, j - i) + " ";
    }
    if(!result.empty()) result.pop_back();
    return result;
}

