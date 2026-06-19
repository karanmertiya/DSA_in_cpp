// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Store the sequence for every character in an array from A to Z, and for space. For each character in the input string, append its corresponding sequence to the result.

string printSequence(string S) {
    string str[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    string output = "";
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == ' ') output += "0";
        else output += str[S[i] - 'A'];
    }
    return output;
}

