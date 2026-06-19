// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Serialize: Use a queue for BFS. For every node, if it's not null, append its value and push its children. If null, append 'null' or '#'. Deserialize: Split the string. Use a queue. The first element is the root. For each node popped from the queue, read the next two elements from the list to form its left and right children, push non-null children to the queue.

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curNode = q.front(); q.pop();
            if(curNode == NULL) s.append("#,");
            else {
                s.append(to_string(curNode->val) + ",");
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

