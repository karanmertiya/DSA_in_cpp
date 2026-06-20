# Day 05 06 Linked List Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 30%;">Example & Constraints</th>
      <th style="width: 15%;">Complexity</th>
      <th style="width: 35%;">Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Ll 01 Reverse Linked List<br><br></b> <a href='https://leetcode.com/problems/reverse-linked-list/' target='_blank'>LeetCode 206</a></td>
      <td><b>Example 1:</b> Input: head = [1,2,3,4,5], Output: [5,4,3,2,1]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Iterative approach: Maintain three pointers (`prev`, `curr`, `next_node`). Re-point `curr->next` to `prev` and slide forward.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseList(ListNode* head) {&#10;    ListNode* prev = nullptr;&#10;    ListNode* curr = head;&#10;    while(curr != nullptr) {&#10;        ListNode* next_node = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next_node;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Ll 02 Middle Of The Linked List<br><br></b> <a href='https://leetcode.com/problems/middle-of-the-linked-list/' target='_blank'>LeetCode 876</a></td>
      <td><b>Example 1:</b> Input: head = [1,2,3,4,5,6], Output: [4,5,6]</td>
      <td><b>Time:</b> O(N/2) &cong; O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use a slow pointer (moves 1 step) and a fast pointer (moves 2 steps). When fast reaches the end, slow is exactly at the middle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* middleNode(ListNode* head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Ll 03 Linked List Cycle<br><br></b> <a href='https://leetcode.com/problems/linked-list-cycle/' target='_blank'>LeetCode 141</a></td>
      <td><b>Example 1:</b> Input: head = [3,2,0,-4], pos = 1, Output: true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Tortoise and Hare algorithm. If there is a cycle, the fast pointer will eventually "lap" and collide with the slow pointer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasCycle(ListNode *head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Ll 04 Merge Two Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-two-sorted-lists/' target='_blank'>LeetCode 21</a></td>
      <td><b>Example 1:</b> Input: list1 = [1,2,4], list2 = [1,3,4], Output: [1,1,2,3,4,4]</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Use a dummy node to easily handle the head of the new list. Compare `list1` and `list2`, attaching the smaller node to `tail`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) {&#10;            tail-&gt;next = list1;&#10;            list1 = list1-&gt;next;&#10;        } else {&#10;            tail-&gt;next = list2;&#10;            list2 = list2-&gt;next;&#10;        }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    ListNode* res = dummy-&gt;next;&#10;    delete dummy;&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Ll 05 Remove Nth Node From End Of List<br><br></b> <a href='https://leetcode.com/problems/remove-nth-node-from-end-of-list/' target='_blank'>LeetCode 19</a></td>
      <td><b>Example 1:</b> Input: head = [1,2,3,4,5], n = 2, Output: [1,2,3,5]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Two-pointer approach. Move `fast` pointer `n` steps ahead. Then move both `slow` and `fast` until `fast` reaches the end. `slow` will be right before the target node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* removeNthFromEnd(ListNode* head, int n) {&#10;    ListNode* fast = head;&#10;    ListNode* slow = head;&#10;    for(int i = 0; i &lt; n; i++) fast = fast-&gt;next;&#10;    if(!fast) return head-&gt;next;&#10;    while(fast-&gt;next) {&#10;        fast = fast-&gt;next;&#10;        slow = slow-&gt;next;&#10;    }&#10;    ListNode* delNode = slow-&gt;next;&#10;    slow-&gt;next = slow-&gt;next-&gt;next;&#10;    delete delNode;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Ll 06 Add Two Numbers<br><br></b> <a href='https://leetcode.com/problems/add-two-numbers/' target='_blank'>LeetCode 2</a></td>
      <td><b>Example 1:</b> Input: l1 = [2,4,3], l2 = [5,6,4], Output: [7,0,8]</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td><b>Explanation:</b> Iterate through both lists, keeping a `carry`. Create new nodes for the `sum % 10`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {&#10;    ListNode* dummy = new ListNode();&#10;    ListNode* temp = dummy;&#10;    int carry = 0;&#10;    while(l1 || l2 || carry) {&#10;        int sum = carry;&#10;        if(l1) { sum += l1-&gt;val; l1 = l1-&gt;next; }&#10;        if(l2) { sum += l2-&gt;val; l2 = l2-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new ListNode(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Ll 07 Intersection Of Two Linked Lists<br><br></b> <a href='https://leetcode.com/problems/intersection-of-two-linked-lists/' target='_blank'>LeetCode 160</a></td>
      <td><b>Example 1:</b> Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3, Output: Intersected at '8'</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Two pointers `a` and `b`. Traverse `A` then `B`, and `B` then `A`. They will meet at the intersection node or `NULL`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {&#10;    ListNode *a = headA, *b = headB;&#10;    while(a != b) {&#10;        a = a ? a-&gt;next : headB;&#10;        b = b ? b-&gt;next : headA;&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Ll 08 Reverse Nodes In K Group<br><br></b> <a href='https://leetcode.com/problems/reverse-nodes-in-k-group/' target='_blank'>LeetCode 25</a></td>
      <td><b>Example 1:</b> Input: head = [1,2,3,4,5], k = 2, Output: [2,1,4,3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Find length of list. Traverse groups of size k. For each group, perform standard linked list reversal. Link the prev group's tail to the current reversed head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseKGroup(ListNode* head, int k) {&#10;    if(!head || k==1) return head;&#10;    int count = 0; ListNode* dummy = new ListNode(0); dummy-&gt;next = head;&#10;    ListNode *cur = head, *nex, *pre = dummy;&#10;    while(cur) { count++; cur = cur-&gt;next; }&#10;    while(count &gt;= k) {&#10;        cur = pre-&gt;next;&#10;        nex = cur-&gt;next;&#10;        for(int i=1; i&lt;k; i++) {&#10;            cur-&gt;next = nex-&gt;next;&#10;            nex-&gt;next = pre-&gt;next;&#10;            pre-&gt;next = nex;&#10;            nex = cur-&gt;next;&#10;        }&#10;        pre = cur;&#10;        count -= k;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Ll 09 Reverse A Linked List In Groups Of Given Size<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive grouping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N/K)</td>
      <td><b>Explanation:</b> Reverse the first `k` nodes of the linked list iteratively. After reversing, the `head` pointer will be the end of the reversed group, and `curr` will point to the next node. Recursively call the function for `curr` and set `head->next` to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct node *reverse (struct node *head, int k) {&#10;    if(!head) return NULL;&#10;    struct node* curr = head, *prev = NULL, *next = NULL;&#10;    int count = 0;&#10;    while(curr &amp;&amp; count &lt; k) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;        count++;&#10;    }&#10;    if(next) head-&gt;next = reverse(next, k);&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Ll 10 Detect Loop In Linked List<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Floyd's Cycle Detection.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use Floyd's Cycle Detection algorithm (Tortoise and Hare). Move `slow` by 1 and `fast` by 2. If they meet, a loop exists. If `fast` reaches NULL, there is no loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool detectLoop(Node* head) {&#10;    Node* slow = head, *fast = head;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Ll 11 Add Two Numbers Represented By Linked Lists<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Reverse, Add, Reverse.</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td><b>Explanation:</b> Reverse both linked lists. Traverse both lists simultaneously, adding the data values of corresponding nodes along with the carry. Create new nodes for the sum and append them to the result list. Finally, reverse the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node* reverse(struct Node* head) {&#10;    Node* prev = NULL, *curr = head, *next = NULL;&#10;    while(curr) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;    }&#10;    return prev;&#10;}&#10;struct Node* addTwoLists(struct Node* first, struct Node* second) {&#10;    first = reverse(first);&#10;    second = reverse(second);&#10;    Node* dummy = new Node(0), *temp = dummy;&#10;    int carry = 0;&#10;    while(first || second || carry) {&#10;        int sum = carry;&#10;        if(first) { sum += first-&gt;data; first = first-&gt;next; }&#10;        if(second) { sum += second-&gt;data; second = second-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new Node(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return reverse(dummy-&gt;next);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Ll 12 Intersection Point In Y Shaped Linked Lists<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use two pointers `a` and `b`. Traverse both lists. When `a` reaches the end, redirect it to `head2`. When `b` reaches the end, redirect it to `head1`. They will meet at the intersection point or both become NULL.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int intersectPoint(Node* head1, Node* head2) {&#10;    Node* a = head1, *b = head2;&#10;    while(a != b) {&#10;        a = (a) ? a-&gt;next : head2;&#10;        b = (b) ? b-&gt;next : head1;&#10;    }&#10;    if(a) return a-&gt;data;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
