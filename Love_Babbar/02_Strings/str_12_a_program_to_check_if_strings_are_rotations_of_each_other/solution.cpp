// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: If the lengths are different, return false. Otherwise, concatenate `s1` with itself (`s1 + s1`). If `s2` is a rotation of `s1`, it must be a substring of the concatenated string.

bool areRotations(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);
}

