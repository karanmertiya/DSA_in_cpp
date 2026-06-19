// Time Complexity: O(N + M)
// Space Complexity: O(M)
// Explanation: Construct an LPS (Longest Proper Prefix which is also Suffix) array for the pattern. Use it to skip unnecessary comparisons while traversing the text.

void computeLPS(string pat, int M, int* lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < M) {
        if(pat[i] == pat[len]) {
            len++; lps[i] = len; i++;
        } else {
            if(len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
}
vector<int> search(string pat, string txt) {
    int M = pat.length(), N = txt.length();
    int lps[M];
    computeLPS(pat, M, lps);
    int i = 0, j = 0;
    vector<int> res;
    while((N - i) >= (M - j)) {
        if(pat[j] == txt[i]) { j++; i++; }
        if(j == M) {
            res.push_back(i - j + 1);
            j = lps[j - 1];
        } else if(i < N && pat[j] != txt[i]) {
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return res;
}

