// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: If lengths don't match, return false. Use three pointers `i`, `j`, `k` for `str1`, `str2`, and `str3`. Traverse `str3`. If `str3[k] == str1[i]`, increment `i` and `k`. Else if `str3[k] == str2[j]`, increment `j` and `k`. Else, it's not a valid shuffle. After the loop, check if both `str1` and `str2` are fully traversed.

bool checkShuffle(string str1, string str2, string str3) {
    if(str1.length() + str2.length() != str3.length()) return false;
    int i = 0, j = 0, k = 0;
    while(k < str3.length()) {
        if(i < str1.length() && str1[i] == str3[k]) i++;
        else if(j < str2.length() && str2[j] == str3[k]) j++;
        else return false;
        k++;
    }
    return (i == str1.length() && j == str2.length());
}

