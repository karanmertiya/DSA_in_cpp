// Time Complexity: O(V^3)
// Space Complexity: O(V^2)
// Explanation: Use Floyd-Warshall to find shortest paths between all pairs of nodes. For each city, count the number of reachable cities within `distanceThreshold`. Return the city with the minimum count (and greatest ID on tie).

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for(int i=0; i<n; i++) dist[i][i] = 0;
    for(auto& e : edges) {
        dist[e[0]][e[1]] = e[2];
        dist[e[1]][e[0]] = e[2];
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int minCities = n, ansCity = -1;
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(dist[i][j] <= distanceThreshold) cnt++;
        }
        if(cnt <= minCities) {
            minCities = cnt;
            ansCity = i;
        }
    }
    return ansCity;
}

