// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Since it is a sorted DLL, set one pointer at the head and one at the tail. If sum == x, add to result and move both. If sum < x, move left pointer next. Else, move right pointer prev.

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    vector<pair<int, int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = head;
    while(right->next != NULL) right = right->next;
    while(left != NULL && right != NULL && left->data < right->data) {
        if(left->data + right->data == target) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if(left->data + right->data < target) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    return ans;
}

