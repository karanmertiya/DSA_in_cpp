// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Compute the hash for the pattern and for the first window of text. Slide the window by removing the leading character's hash and adding the trailing character's hash. If hashes match, check the characters one by one.

vector<int> search(string pat, string txt) {
    int d = 256, q = 101;
    int M = pat.length(), N = txt.length();
    int i, j, p = 0, t = 0, h = 1;
    vector<int> res;
    for (i = 0; i < M - 1; i++) h = (h * d) % q;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if (j == M) res.push_back(i + 1);
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
    return res;
}

