// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: If the lengths of `s` and `goal` are not equal, return false. Otherwise, concatenate `s` with itself (`s + s`). If `goal` is a substring of `s + s`, then it's a rotated string.

bool rotateString(string s, string goal) {
    if(s.length() != goal.length()) return false;
    string doubleS = s + s;
    return doubleS.find(goal) != string::npos;
}

