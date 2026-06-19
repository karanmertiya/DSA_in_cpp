// Time Complexity: O(N * M * log(N * M)) where N=accounts, M=max emails
// Space Complexity: O(N * M)
// Explanation: Create a DSU of size N (number of accounts). Map each email to its first seen account ID. If an email is seen again, union the current account ID with the mapped account ID. Then group emails by the ultimate parent of their account ID. Sort emails in each group and format the result.

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> mailNode;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < accounts[i].size(); j++) {
            string mail = accounts[i][j];
            if(mailNode.find(mail) == mailNode.end()) {
                mailNode[mail] = i;
            } else {
                ds.unionByRank(i, mailNode[mail]);
            }
        }
    }
    vector<vector<string>> mergedMails(n);
    for(auto& it : mailNode) {
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergedMails[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i = 0; i < n; i++) {
        if(mergedMails[i].empty()) continue;
        sort(mergedMails[i].begin(), mergedMails[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(string& mail : mergedMails[i]) temp.push_back(mail);
        ans.push_back(temp);
    }
    return ans;
}

