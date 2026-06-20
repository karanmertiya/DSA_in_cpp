// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a queue. Push root. Then loop: Pop a node `curr`. While `curr` is not null, add its value to result, push `curr->left` to queue, and move to `curr->right`.

vector<int> diagonal(Node *root) {
    vector<int> res;
    if(!root) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        while(curr) {
            res.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            curr = curr->right;
        }
    }
    return res;
}

