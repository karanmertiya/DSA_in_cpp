// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse both linked lists to form the respective numbers modulo a given large number (e.g., 10^9+7). Then multiply the two formed numbers and return the result modulo the same large number.

long long multiplyTwoLists(Node *l1, Node *l2) {
    long long N = 1000000007;
    long long num1 = 0, num2 = 0;
    while(l1 || l2) {
        if(l1) {
            num1 = (num1 * 10)%N + l1->data;
            l1 = l1->next;
        }
        if(l2) {
            num2 = (num2 * 10)%N + l2->data;
            l2 = l2->next;
        }
    }
    return (num1 * num2) % N;
}

