// Time Complexity: O(N)
// Space Complexity: O(k)
// Explanation: Count total nodes `N`. Each part will have at least `N // k` nodes, and the first `N % k` parts will have one extra node. Iterate and break the links.

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans(k, NULL);
    int n = 0;
    for(ListNode* node = head; node; node = node->next) n++;
    int part = n / k, extra = n % k;
    ListNode* node = head, *prev = NULL;
    for(int i = 0; node && i < k; i++, extra--) {
        ans[i] = node;
        for(int j = 0; j < part + (extra > 0); j++) {
            prev = node;
            node = node->next;
        }
        if(prev) prev->next = NULL;
    }
    return ans;
}

