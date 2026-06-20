// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: 3 Steps O(1) space. 1) Insert copy nodes right after original nodes. 2) Set random pointers for copy nodes: `iter->next->random = iter->random ? iter->random->next : NULL`. 3) Separate the two lists.

Node* copyRandomList(Node* head) {
    if(!head) return NULL;
    Node* iter = head;
    while(iter) {
        Node* copy = new Node(iter->val);
        copy->next = iter->next;
        iter->next = copy;
        iter = copy->next;
    }
    iter = head;
    while(iter) {
        if(iter->random) iter->next->random = iter->random->next;
        iter = iter->next->next;
    }
    iter = head; Node* pseudoHead = new Node(0);
    Node* copyIter = pseudoHead;
    while(iter) {
        Node* nextIter = iter->next->next;
        copyIter->next = iter->next;
        iter->next = nextIter;
        copyIter = copyIter->next;
        iter = nextIter;
    }
    return pseudoHead->next;
}

