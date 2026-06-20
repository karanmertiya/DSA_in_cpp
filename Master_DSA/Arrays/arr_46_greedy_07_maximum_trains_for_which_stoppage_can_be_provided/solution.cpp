// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Optimal: Group trains by platform. For each platform, this reduces to the Activity Selection Problem. Sort the trains by departure time and greedily pick non-overlapping trains.

struct Train { int arr, dep, plat; };
bool comp(Train a, Train b) { return a.dep < b.dep; }
int maxStop(vector<Train>& trains, int n, int m) {
    vector<vector<pair<int, int>>> platforms(m + 1);
    for(int i = 0; i < n; i++) {
        platforms[trains[i].plat].push_back({trains[i].dep, trains[i].arr});
    }
    int count = 0;
    for(int i = 1; i <= m; i++) {
        if(platforms[i].size() == 0) continue;
        sort(platforms[i].begin(), platforms[i].end());
        count++;
        int lastDep = platforms[i][0].first;
        for(int j = 1; j < platforms[i].size(); j++) {
            if(platforms[i][j].second >= lastDep) {
                count++;
                lastDep = platforms[i][j].first;
            }
        }
    }
    return count;
}

