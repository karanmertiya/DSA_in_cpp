// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: First, calculate the length of the list. Then, determine base size `len / k` and extra nodes `len % k`. Iterate through the list, breaking it into parts of appropriate sizes.

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    ListNode* curr = head;
    while(curr) { len++; curr = curr->next; }
    int partSize = len / k, extra = len % k;
    vector<ListNode*> ans;
    curr = head;
    for(int i=0; i<k; i++) {
        ans.push_back(curr);
        int currentPartSize = partSize + (extra > 0 ? 1 : 0);
        extra--;
        for(int j=0; j<currentPartSize - 1; j++) {
            if(curr) curr = curr->next;
        }
        if(curr) {
            ListNode* nextPart = curr->next;
            curr->next = NULL;
            curr = nextPart;
        }
    }
    return ans;
}

