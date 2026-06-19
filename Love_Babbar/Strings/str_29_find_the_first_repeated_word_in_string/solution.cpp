// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Split the string into words. Iterate through the words. If a word is already in the hash set, it is the first repeated word. Return it. Else, add it to the hash set.

string firstRepeatedWord(string s) {
    unordered_set<string> st;
    string word = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == ':' || s[i] == '.' || s[i] == '-') {
            if(word != "") {
                if(st.find(word) != st.end()) return word;
                st.insert(word);
                word = "";
            }
        } else word += s[i];
    }
    if(word != "" && st.find(word) != st.end()) return word;
    return "No Repetition";
}

