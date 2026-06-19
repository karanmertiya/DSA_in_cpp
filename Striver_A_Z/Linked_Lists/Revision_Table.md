# Linked Lists Revision Table

<table border="1">
  <thead>
    <tr>
      <th rowspan="2" style="width: 5%;">S.No</th>
      <th rowspan="2" style="width: 15%;">Problem Name</th>
      <th rowspan="2" style="width: 25%;">Example & Constraints</th>
      <th rowspan="2" style="width: 10%;">Complexity</th>
      <th colspan="2" style="width: 20%;">Conditions & Edge Cases</th>
      <th rowspan="2" style="width: 25%;">Logic</th>
    </tr>
    <tr>
      <th>Dependencies / Setup</th>
      <th>Edge Case Handling</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="1">1</td>
      <td rowspan="1">Ll 01 Reverse Linked List<br><br></b> <a href='https://leetcode.com/problems/reverse-linked-list/' target='_blank'>LeetCode 206</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5], Output: [5,4,3,2,1]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Null List:</b> Automatically handled because the `while` loop checks `curr != NULL`.</td>
      <td><b>Explanation:</b> Iterative approach: Maintain three pointers (`prev`, `curr`, `next_node`). Re-point `curr->next` to `prev` and slide forward.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseList(ListNode* head) {&#10;    ListNode* prev = nullptr;&#10;    ListNode* curr = head;&#10;    while(curr != nullptr) {&#10;        ListNode* next_node = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next_node;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Ll 02 Middle Of The Linked List<br><br></b> <a href='https://leetcode.com/problems/middle-of-the-linked-list/' target='_blank'>LeetCode 876</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5,6], Output: [4,5,6]</td>
      <td><b>Time:</b> O(N/2) &cong; O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Even/Odd Length:</b> Loop condition `fast != NULL && fast->next != NULL` handles both.</td>
      <td><b>Explanation:</b> Use a slow pointer (moves 1 step) and a fast pointer (moves 2 steps). When fast reaches the end, slow is exactly at the middle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* middleNode(ListNode* head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Ll 03 Linked List Cycle<br><br></b> <a href='https://leetcode.com/problems/linked-list-cycle/' target='_blank'>LeetCode 141</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [3,2,0,-4], pos = 1, Output: true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>No Cycle:</b> Handled if `fast == NULL` or `fast->next == NULL`.</td>
      <td><b>Explanation:</b> Tortoise and Hare algorithm. If there is a cycle, the fast pointer will eventually "lap" and collide with the slow pointer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasCycle(ListNode *head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Ll 04 Merge Two Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-two-sorted-lists/' target='_blank'>LeetCode 21</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: list1 = [1,2,4], list2 = [1,3,4], Output: [1,1,2,3,4,4]</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Leftover Nodes:</b> When one list exhausts, directly attach the entirety of the other list via `tail->next = list1 ? list1 : list2`.</td>
      <td><b>Explanation:</b> Use a dummy node to easily handle the head of the new list. Compare `list1` and `list2`, attaching the smaller node to `tail`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) {&#10;            tail-&gt;next = list1;&#10;            list1 = list1-&gt;next;&#10;        } else {&#10;            tail-&gt;next = list2;&#10;            list2 = list2-&gt;next;&#10;        }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    ListNode* res = dummy-&gt;next;&#10;    delete dummy;&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Ll 05 Remove Nth Node From End Of List<br><br></b> <a href='https://leetcode.com/problems/remove-nth-node-from-end-of-list/' target='_blank'>LeetCode 19</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5], n = 2, Output: [1,2,3,5]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Remove Head:</b> If `fast` becomes NULL after moving `n` steps, it means the head needs to be removed. Return `head->next`.</td>
      <td><b>Explanation:</b> Two-pointer approach. Move `fast` pointer `n` steps ahead. Then move both `slow` and `fast` until `fast` reaches the end. `slow` will be right before the target node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* removeNthFromEnd(ListNode* head, int n) {&#10;    ListNode* fast = head;&#10;    ListNode* slow = head;&#10;    for(int i = 0; i &lt; n; i++) fast = fast-&gt;next;&#10;    if(!fast) return head-&gt;next;&#10;    while(fast-&gt;next) {&#10;        fast = fast-&gt;next;&#10;        slow = slow-&gt;next;&#10;    }&#10;    ListNode* delNode = slow-&gt;next;&#10;    slow-&gt;next = slow-&gt;next-&gt;next;&#10;    delete delNode;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Ll 06 Add Two Numbers<br><br></b> <a href='https://leetcode.com/problems/add-two-numbers/' target='_blank'>LeetCode 2</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: l1 = [2,4,3], l2 = [5,6,4], Output: [7,0,8]</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td>-</td>
      <td><b>Leftover Carry:</b> After the loop, if `carry > 0`, we must append one last node.</td>
      <td><b>Explanation:</b> Iterate through both lists, keeping a `carry`. Create new nodes for the `sum % 10`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {&#10;    ListNode* dummy = new ListNode();&#10;    ListNode* temp = dummy;&#10;    int carry = 0;&#10;    while(l1 || l2 || carry) {&#10;        int sum = carry;&#10;        if(l1) { sum += l1-&gt;val; l1 = l1-&gt;next; }&#10;        if(l2) { sum += l2-&gt;val; l2 = l2-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new ListNode(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Ll 07 Intersection Of Two Linked Lists<br><br></b> <a href='https://leetcode.com/problems/intersection-of-two-linked-lists/' target='_blank'>LeetCode 160</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3, Output: Intersected at '8'</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>No Intersection:</b> If no intersection, both pointers will simultaneously hit `NULL` at the end of their second traversal.</td>
      <td><b>Explanation:</b> Two pointers `a` and `b`. Traverse `A` then `B`, and `B` then `A`. They will meet at the intersection node or `NULL`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {&#10;    ListNode *a = headA, *b = headB;&#10;    while(a != b) {&#10;        a = a ? a-&gt;next : headB;&#10;        b = b ? b-&gt;next : headA;&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Ll 08 Reverse Nodes In K Group<br><br></b> <a href='https://leetcode.com/problems/reverse-nodes-in-k-group/' target='_blank'>LeetCode 25</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5], k = 2, Output: [2,1,4,3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Remaining nodes < K:</b> The loop terminates early, leaving the remaining list intact.</td>
      <td><b>Explanation:</b> Find length of list. Traverse groups of size k. For each group, perform standard linked list reversal. Link the prev group's tail to the current reversed head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseKGroup(ListNode* head, int k) {&#10;    if(!head || k==1) return head;&#10;    int count = 0; ListNode* dummy = new ListNode(0); dummy-&gt;next = head;&#10;    ListNode *cur = head, *nex, *pre = dummy;&#10;    while(cur) { count++; cur = cur-&gt;next; }&#10;    while(count &gt;= k) {&#10;        cur = pre-&gt;next;&#10;        nex = cur-&gt;next;&#10;        for(int i=1; i&lt;k; i++) {&#10;            cur-&gt;next = nex-&gt;next;&#10;            nex-&gt;next = pre-&gt;next;&#10;            pre-&gt;next = nex;&#10;            nex = cur-&gt;next;&#10;        }&#10;        pre = cur;&#10;        count -= k;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Ll 09 Intersection Of Two Linked Lists<br><br></b> <a href='https://leetcode.com/problems/intersection-of-two-linked-lists/' target='_blank'>LeetCode 160</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], Output: Intersected at '8'</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>No intersection:</b> Both pointers will reach NULL simultaneously after swapping lists once.</td>
      <td><b>Explanation:</b> Two pointers. Pointer A traverses list A, then jumps to list B. Pointer B traverses list B, then jumps to list A. They traverse the same total distance (A+B) and will meet at the intersection, or at NULL.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {&#10;    if(!headA || !headB) return NULL;&#10;    ListNode *a = headA, *b = headB;&#10;    while(a != b) {&#10;        a = a ? a-&gt;next : headB;&#10;        b = b ? b-&gt;next : headA;&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Ll 10 Reverse Nodes In K Group<br><br></b> <a href='https://leetcode.com/problems/reverse-nodes-in-k-group/' target='_blank'>LeetCode 25</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5], k = 2, Output: [2,1,4,3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterative approach. Calculate the length. Use a dummy node. Maintain `pre`, `curr`, and `nex` pointers. Reverse `k-1` links in each group. Decrement length by `k` until length < `k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseKGroup(ListNode* head, int k) {&#10;    if(!head || k==1) return head;&#10;    int length = 0;&#10;    ListNode* temp = head;&#10;    while(temp) { length++; temp = temp-&gt;next; }&#10;    ListNode* dummy = new ListNode(0);&#10;    dummy-&gt;next = head;&#10;    ListNode *pre = dummy, *curr = dummy, *nex = dummy;&#10;    while(length &gt;= k) {&#10;        curr = pre-&gt;next;&#10;        nex = curr-&gt;next;&#10;        for(int i=1; i&lt;k; i++) {&#10;            curr-&gt;next = nex-&gt;next;&#10;            nex-&gt;next = pre-&gt;next;&#10;            pre-&gt;next = nex;&#10;            nex = curr-&gt;next;&#10;        }&#10;        pre = curr; length -= k;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Ll 11 Copy List With Random Pointer<br><br></b> <a href='https://leetcode.com/problems/copy-list-with-random-pointer/' target='_blank'>LeetCode 138</a></td>
      <td rowspan="1"><b>Example 1:</b> Return a deep copy.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 3 Steps O(1) space. 1) Insert copy nodes right after original nodes. 2) Set random pointers for copy nodes: `iter->next->random = iter->random ? iter->random->next : NULL`. 3) Separate the two lists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* copyRandomList(Node* head) {&#10;    if(!head) return NULL;&#10;    Node* iter = head;&#10;    while(iter) {&#10;        Node* copy = new Node(iter-&gt;val);&#10;        copy-&gt;next = iter-&gt;next;&#10;        iter-&gt;next = copy;&#10;        iter = copy-&gt;next;&#10;    }&#10;    iter = head;&#10;    while(iter) {&#10;        if(iter-&gt;random) iter-&gt;next-&gt;random = iter-&gt;random-&gt;next;&#10;        iter = iter-&gt;next-&gt;next;&#10;    }&#10;    iter = head; Node* pseudoHead = new Node(0);&#10;    Node* copyIter = pseudoHead;&#10;    while(iter) {&#10;        Node* nextIter = iter-&gt;next-&gt;next;&#10;        copyIter-&gt;next = iter-&gt;next;&#10;        iter-&gt;next = nextIter;&#10;        copyIter = copyIter-&gt;next;&#10;        iter = nextIter;&#10;    }&#10;    return pseudoHead-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Ll 16 Rotate List<br><br></b> <a href='https://leetcode.com/problems/rotate-list/' target='_blank'>LeetCode 61</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5], k = 2, Output: [4,5,1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>k = 0 or empty list:</b> Return head immediately.</td>
      <td><b>Explanation:</b> Compute the length of the list, and make it a circular list by connecting the last node to head. Then find the new break point `(length - k % length)`. Break the circle and return the new head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* rotateRight(ListNode* head, int k) {&#10;    if(!head || !head-&gt;next || k == 0) return head;&#10;    int len = 1;&#10;    ListNode* cur = head;&#10;    while(cur-&gt;next) {&#10;        len++;&#10;        cur = cur-&gt;next;&#10;    }&#10;    cur-&gt;next = head;&#10;    k = k % len;&#10;    k = len - k;&#10;    while(k--) cur = cur-&gt;next;&#10;    head = cur-&gt;next;&#10;    cur-&gt;next = NULL;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Ll 17 Flattening A Linked List<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursively merge.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recursively flatten the `next` list, then merge the current list (`bottom` pointers) with the flattened `next` list, similar to merging two sorted linked lists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* mergeTwoLists(Node* a, Node* b) {&#10;    Node* temp = new Node(0);&#10;    Node* res = temp;&#10;    while(a != NULL &amp;&amp; b != NULL) {&#10;        if(a-&gt;data &lt; b-&gt;data) { temp-&gt;bottom = a; temp = temp-&gt;bottom; a = a-&gt;bottom; }&#10;        else { temp-&gt;bottom = b; temp = temp-&gt;bottom; b = b-&gt;bottom; }&#10;    }&#10;    if(a) temp-&gt;bottom = a;&#10;    else temp-&gt;bottom = b;&#10;    return res-&gt;bottom;&#10;}&#10;Node *flatten(Node *root) {&#10;    if(root == NULL || root-&gt;next == NULL) return root;&#10;    root-&gt;next = flatten(root-&gt;next);&#10;    root = mergeTwoLists(root, root-&gt;next);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Ll 18 Sort A Linked List<br><br></b> <a href='https://leetcode.com/problems/sort-list/' target='_blank'>LeetCode 148</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [4,2,1,3], Output: [1,2,3,4]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(log N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Merge Sort. Use fast/slow pointers to find the middle of the linked list. Split into two halves, recursively sort both halves, then merge the two sorted halves.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode dummy(0);&#10;    ListNode* tail = &amp;dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) { tail-&gt;next = list1; list1 = list1-&gt;next; }&#10;        else { tail-&gt;next = list2; list2 = list2-&gt;next; }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    return dummy.next;&#10;}&#10;ListNode* sortList(ListNode* head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    ListNode *slow = head, *fast = head-&gt;next;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    ListNode* mid = slow-&gt;next;&#10;    slow-&gt;next = NULL;&#10;    return mergeTwoLists(sortList(head), sortList(mid));&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Ll 19 Find Pairs With Given Sum In Doubly Linked List<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointer approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Since it is a sorted DLL, set one pointer at the head and one at the tail. If sum == x, add to result and move both. If sum < x, move left pointer next. Else, move right pointer prev.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;pair&lt;int, int&gt;&gt; findPairsWithGivenSum(Node *head, int target) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; ans;&#10;    if(head == NULL) return ans;&#10;    Node* left = head;&#10;    Node* right = head;&#10;    while(right-&gt;next != NULL) right = right-&gt;next;&#10;    while(left != NULL &amp;&amp; right != NULL &amp;&amp; left-&gt;data &lt; right-&gt;data) {&#10;        if(left-&gt;data + right-&gt;data == target) {&#10;            ans.push_back({left-&gt;data, right-&gt;data});&#10;            left = left-&gt;next;&#10;            right = right-&gt;prev;&#10;        } else if(left-&gt;data + right-&gt;data &lt; target) {&#10;            left = left-&gt;next;&#10;        } else {&#10;            right = right-&gt;prev;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Ll 20 Remove Duplicates From Sorted Doubly Linked List<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Skip duplicates.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Traverse the DLL. While `next` node has the same value, bypass it by updating `curr->next` and `curr->next->prev`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node * removeDuplicates(struct Node *head) {&#10;    Node* curr = head;&#10;    while(curr != NULL) {&#10;        Node* nextNode = curr-&gt;next;&#10;        while(nextNode != NULL &amp;&amp; nextNode-&gt;data == curr-&gt;data) {&#10;            nextNode = nextNode-&gt;next;&#10;        }&#10;        curr-&gt;next = nextNode;&#10;        if(nextNode != NULL) nextNode-&gt;prev = curr;&#10;        curr = curr-&gt;next;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Ll 21 Reverse A Doubly Linked List<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Swap prev and next.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Traverse the DLL. For each node, swap its `prev` and `next` pointers. The new head will be the last node processed.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* reverseDLL(Node * head) {&#10;    if(head == NULL || head-&gt;next == NULL) return head;&#10;    Node* curr = head;&#10;    Node* temp = NULL;&#10;    while(curr != NULL) {&#10;        temp = curr-&gt;prev;&#10;        curr-&gt;prev = curr-&gt;next;&#10;        curr-&gt;next = temp;&#10;        curr = curr-&gt;prev;&#10;    }&#10;    return temp-&gt;prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Ll 22 Delete All Occurrences Of A Key In Dll<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Update links.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Head deletion:</b> handled by reassigning head pointer.</td>
      <td><b>Explanation:</b> Traverse the list. If `node->data == x`, update the `next` pointer of `node->prev` and `prev` pointer of `node->next`. If the node is head, update head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void deleteAllOccurOfX(struct Node** head_ref, int x) {&#10;    Node* curr = *head_ref;&#10;    while(curr != NULL) {&#10;        if(curr-&gt;data == x) {&#10;            if(curr == *head_ref) *head_ref = curr-&gt;next;&#10;            if(curr-&gt;prev != NULL) curr-&gt;prev-&gt;next = curr-&gt;next;&#10;            if(curr-&gt;next != NULL) curr-&gt;next-&gt;prev = curr-&gt;prev;&#10;            Node* toDelete = curr;&#10;            curr = curr-&gt;next;&#10;            free(toDelete);&#10;        } else {&#10;            curr = curr-&gt;next;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Ll 23 Swap Nodes In Pairs<br><br></b> <a href='https://leetcode.com/problems/swap-nodes-in-pairs/' target='_blank'>LeetCode 24</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4], Output: [2,1,4,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a dummy node. Iteratively swap `curr` and `curr->next`. Keep track of `prev` to link the swapped pairs to the rest of the list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* swapPairs(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    dummy-&gt;next = head;&#10;    ListNode* prev = dummy;&#10;    while(prev-&gt;next != NULL &amp;&amp; prev-&gt;next-&gt;next != NULL) {&#10;        ListNode* first = prev-&gt;next;&#10;        ListNode* second = prev-&gt;next-&gt;next;&#10;        first-&gt;next = second-&gt;next;&#10;        second-&gt;next = first;&#10;        prev-&gt;next = second;&#10;        prev = first;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Ll 24 Odd Even Linked List<br><br></b> <a href='https://leetcode.com/problems/odd-even-linked-list/' target='_blank'>LeetCode 328</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: head = [1,2,3,4,5], Output: [1,3,5,2,4]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain two pointers `odd` and `even`. Keep the `evenHead`. Loop to link `odd->next = even->next` and `even->next = odd->next`. Finally, link `odd->next = evenHead`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* oddEvenList(ListNode* head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    ListNode *odd = head, *even = head-&gt;next, *evenHead = even;&#10;    while(even &amp;&amp; even-&gt;next) {&#10;        odd-&gt;next = odd-&gt;next-&gt;next;&#10;        even-&gt;next = even-&gt;next-&gt;next;&#10;        odd = odd-&gt;next;&#10;        even = even-&gt;next;&#10;    }&#10;    odd-&gt;next = evenHead;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Ll 25 Split Linked List In Parts<br><br></b> <a href='https://leetcode.com/problems/split-linked-list-in-parts/' target='_blank'>LeetCode 725</a></td>
      <td rowspan="1"><b>Example 1:</b> Distribution math.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>-</td>
      <td><b>k > length:</b> Fill remaining parts with null.</td>
      <td><b>Explanation:</b> First, calculate the length of the list. Then, determine base size `len / k` and extra nodes `len % k`. Iterate through the list, breaking it into parts of appropriate sizes.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;ListNode*&gt; splitListToParts(ListNode* head, int k) {&#10;    int len = 0;&#10;    ListNode* curr = head;&#10;    while(curr) { len++; curr = curr-&gt;next; }&#10;    int partSize = len / k, extra = len % k;&#10;    vector&lt;ListNode*&gt; ans;&#10;    curr = head;&#10;    for(int i=0; i&lt;k; i++) {&#10;        ans.push_back(curr);&#10;        int currentPartSize = partSize + (extra &gt; 0 ? 1 : 0);&#10;        extra--;&#10;        for(int j=0; j&lt;currentPartSize - 1; j++) {&#10;            if(curr) curr = curr-&gt;next;&#10;        }&#10;        if(curr) {&#10;            ListNode* nextPart = curr-&gt;next;&#10;            curr-&gt;next = NULL;&#10;            curr = nextPart;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
