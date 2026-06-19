// Time Complexity: O(N * L + K)
// Space Complexity: O(K)
// Explanation: Compare adjacent words in the sorted dictionary. The first differing character creates a directed edge `char1 -> char2` indicating `char1` comes before `char2`. Build a directed graph and perform Topological Sorting to get the order.

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for(int i = 0; i < N - 1; i++) {
        string s1 = dict[i], s2 = dict[i+1];
        int len = min(s1.length(), s2.length());
        for(int j = 0; j < len; j++) {
            if(s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> inDegree(K, 0);
    for(int i = 0; i < K; i++) {
        for(int nbr : adj[i]) inDegree[nbr]++;
    }
    queue<int> q;
    for(int i = 0; i < K; i++) if(inDegree[i] == 0) q.push(i);
    string ans = "";
    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans += (char)(node + 'a');
        for(int nbr : adj[node]) {
            inDegree[nbr]--;
            if(inDegree[nbr] == 0) q.push(nbr);
        }
    }
    return ans;
}

