// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Compute hash for pattern and first window of text. Slide window: subtract leading char's hash contribution, shift, and add trailing char. If hashes match, explicitly check strings to avoid collisions.

vector<int> search(string pat, string txt) {
    vector<int> res;
    int d = 256, q = 101;
    int m = pat.length(), n = txt.length();
    int i, j, p = 0, t = 0, h = 1;
    for(i=0; i<m-1; i++) h = (h * d) % q;
    for(i=0; i<m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for(i=0; i<=n-m; i++) {
        if(p == t) {
            for(j=0; j<m; j++) if(txt[i+j] != pat[j]) break;
            if(j == m) res.push_back(i+1); // 1-based index usually
        }
        if(i < n-m) {
            t = (d * (t - txt[i] * h) + txt[i+m]) % q;
            if(t < 0) t += q;
        }
    }
    return res;
}

