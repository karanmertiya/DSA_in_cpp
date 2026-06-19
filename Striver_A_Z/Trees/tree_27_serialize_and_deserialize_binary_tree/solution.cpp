// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use Level Order Traversal (BFS) to serialize into a comma-separated string, using '#' for null. For deserialization, split string and use a queue to rebuild.

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(node == NULL) s += "#,";
            else {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            getline(s, str, ',');
            if(str == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s, str, ',');
            if(str == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

