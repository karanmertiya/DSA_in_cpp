// Time Complexity: O(N)
// Space Complexity: O(1) excluding output
// Explanation: Iterate from the end of the string. The first odd digit found marks the end of the largest odd integer (since picking all digits from index 0 to this odd digit yields the largest value). Return the substring `num[0..i]`. If no odd digit is found, return empty string.

string largestOddNumber(string num) {
    for(int i = num.length() - 1; i >= 0; i--) {
        if((num[i] - '0') % 2 != 0) return num.substr(0, i + 1);
    }
    return "";
}

