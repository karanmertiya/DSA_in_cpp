// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Explanation: Traverse the first linked list and compute the number it represents modulo 10^9+7. Do the same for the second linked list. Multiply the two numbers and return the result modulo 10^9+7.

long long multiplyTwoLists(Node *l1, Node *l2) {
    long long num1 = 0, num2 = 0;
    long long mod = 1e9 + 7;
    while(l1) {
        num1 = (num1 * 10 + l1->data) % mod;
        l1 = l1->next;
    }
    while(l2) {
        num2 = (num2 * 10 + l2->data) % mod;
        l2 = l2->next;
    }
    return (num1 * num2) % mod;
}

