// Time Complexity: O(N * M)
// Space Complexity: O(256)
// Explanation: Create a Bad Character table for the pattern, which stores the last occurrence of each character. Align pattern with text. Compare from right to left. If mismatch, shift the pattern so that the mismatched character in text aligns with its last occurrence in the pattern. If not present, shift pattern past it.

void search(string txt, string pat) {
    int m = pat.length(), n = txt.length();
    int badChar[256];
    for(int i = 0; i < 256; i++) badChar[i] = -1;
    for(int i = 0; i < m; i++) badChar[(int)pat[i]] = i;
    int s = 0;
    while(s <= (n - m)) {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j]) j--;
        if(j < 0) {
            cout << "Pattern occurs at shift = " << s << endl;
            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        } else {
            s += max(1, j - badChar[txt[s + j]]);
        }
    }
}

