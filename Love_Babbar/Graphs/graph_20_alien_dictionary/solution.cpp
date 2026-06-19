// Time Complexity: O(N * length of words + K)
// Space Complexity: O(K)
// Explanation: Compare adjacent words. The first mismatching character defines a directed edge `char1 -> char2`. Create an adjacency list of these edges. Then perform a topological sort to get the valid character order.

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for(int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.length(), s2.length());
        for(int ptr = 0; ptr < len; ptr++) {
            if(s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    int indegree[K] = {0};
    for(int i = 0; i < K; i++) {
        for(auto it : adj[i]) indegree[it]++;
    }
    queue<int> q;
    for(int i = 0; i < K; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    string topo = "";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo += (char)(node + 'a');
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

