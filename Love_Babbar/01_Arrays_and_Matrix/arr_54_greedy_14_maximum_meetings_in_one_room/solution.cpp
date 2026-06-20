// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Store `(start, end, index)`. Sort by end time. Pick the first meeting. For subsequent meetings, if `start > last_picked_end`, pick it and update `last_picked_end`. Return sorted indices.

struct Meeting { int s, e, pos; };
bool comp(Meeting a, Meeting b) {
    if(a.e == b.e) return a.pos < b.pos;
    return a.e < b.e;
}
vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
    vector<Meeting> m(N);
    for(int i = 0; i < N; i++) { m[i].s = S[i]; m[i].e = F[i]; m[i].pos = i + 1; }
    sort(m.begin(), m.end(), comp);
    vector<int> ans;
    ans.push_back(m[0].pos);
    int last_e = m[0].e;
    for(int i = 1; i < N; i++) {
        if(m[i].s > last_e) {
            ans.push_back(m[i].pos);
            last_e = m[i].e;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

