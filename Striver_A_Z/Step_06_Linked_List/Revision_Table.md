# Step 06 Linked List Revision Table

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
      <td>Hash 01 Design Hashset<br><br></b> <a href="https://leetcode.com/problems/design-hashset/" target="_blank">LeetCode 705</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Array of Linked Lists (Chaining).</td>
      <td><b>Time:</b> O(1) average, O(N) worst case<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a large array (e.g., size 10000) of linked lists or vectors. The hash function maps `key` to `key % 10000`. To add, if not present in the bucket, append it. To remove, find and erase. To contain, iterate through bucket.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MyHashSet {&#10;    vector&lt;list&lt;int&gt;&gt; buckets;&#10;    int size = 10000;&#10;public:&#10;    MyHashSet() {&#10;        buckets.resize(size);&#10;    }&#10;    void add(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        if(it == buckets[i].end()) buckets[i].push_back(key);&#10;    }&#10;    void remove(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        if(it != buckets[i].end()) buckets[i].erase(it);&#10;    }&#10;    bool contains(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        return it != buckets[i].end();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Ll 02 Reverse Linked List<br><br></b> <a href="https://leetcode.com/problems/reverse-linked-list/" target="_blank">LeetCode 206</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4,5], Output: [5,4,3,2,1]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Iterative approach: Maintain three pointers (`prev`, `curr`, `next_node`). Re-point `curr->next` to `prev` and slide forward.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseList(ListNode* head) {&#10;    ListNode* prev = nullptr;&#10;    ListNode* curr = head;&#10;    while(curr != nullptr) {&#10;        ListNode* next_node = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next_node;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Ll 03 Middle Of The Linked List<br><br></b> <a href="https://leetcode.com/problems/middle-of-the-linked-list/" target="_blank">LeetCode 876</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4,5,6], Output: [4,5,6]</td>
      <td><b>Time:</b> O(N/2) &cong; O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use a slow pointer (moves 1 step) and a fast pointer (moves 2 steps). When fast reaches the end, slow is exactly at the middle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* middleNode(ListNode* head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Ll 04 Linked List Cycle<br><br></b> <a href="https://leetcode.com/problems/linked-list-cycle/" target="_blank">LeetCode 141</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: head = [3,2,0,-4], pos = 1, Output: true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Tortoise and Hare algorithm. If there is a cycle, the fast pointer will eventually "lap" and collide with the slow pointer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasCycle(ListNode *head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Ll 05 Merge Two Sorted Lists<br><br></b> <a href="https://leetcode.com/problems/merge-two-sorted-lists/" target="_blank">LeetCode 21</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: list1 = [1,2,4], list2 = [1,3,4], Output: [1,1,2,3,4,4]</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Use a dummy node to easily handle the head of the new list. Compare `list1` and `list2`, attaching the smaller node to `tail`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) {&#10;            tail-&gt;next = list1;&#10;            list1 = list1-&gt;next;&#10;        } else {&#10;            tail-&gt;next = list2;&#10;            list2 = list2-&gt;next;&#10;        }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    ListNode* res = dummy-&gt;next;&#10;    delete dummy;&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Ll 06 Remove Nth Node From End Of List<br><br></b> <a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list/" target="_blank">LeetCode 19</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4,5], n = 2, Output: [1,2,3,5]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Two-pointer approach. Move `fast` pointer `n` steps ahead. Then move both `slow` and `fast` until `fast` reaches the end. `slow` will be right before the target node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* removeNthFromEnd(ListNode* head, int n) {&#10;    ListNode* fast = head;&#10;    ListNode* slow = head;&#10;    for(int i = 0; i &lt; n; i++) fast = fast-&gt;next;&#10;    if(!fast) return head-&gt;next;&#10;    while(fast-&gt;next) {&#10;        fast = fast-&gt;next;&#10;        slow = slow-&gt;next;&#10;    }&#10;    ListNode* delNode = slow-&gt;next;&#10;    slow-&gt;next = slow-&gt;next-&gt;next;&#10;    delete delNode;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Ll 07 Add Two Numbers<br><br></b> <a href="https://leetcode.com/problems/add-two-numbers/" target="_blank">LeetCode 2</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: l1 = [2,4,3], l2 = [5,6,4], Output: [7,0,8]</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td><b>Explanation:</b> Iterate through both lists, keeping a `carry`. Create new nodes for the `sum % 10`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {&#10;    ListNode* dummy = new ListNode();&#10;    ListNode* temp = dummy;&#10;    int carry = 0;&#10;    while(l1 || l2 || carry) {&#10;        int sum = carry;&#10;        if(l1) { sum += l1-&gt;val; l1 = l1-&gt;next; }&#10;        if(l2) { sum += l2-&gt;val; l2 = l2-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new ListNode(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Ll 08 Intersection Of Two Linked Lists<br><br></b> <a href="https://leetcode.com/problems/intersection-of-two-linked-lists/" target="_blank">LeetCode 160</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Apna College, Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3, Output: Intersected at '8'</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Two pointers `a` and `b`. Traverse `A` then `B`, and `B` then `A`. They will meet at the intersection node or `NULL`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {&#10;    ListNode *a = headA, *b = headB;&#10;    while(a != b) {&#10;        a = a ? a-&gt;next : headB;&#10;        b = b ? b-&gt;next : headA;&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Ll 09 Reverse Nodes In K Group<br><br></b> <a href="https://leetcode.com/problems/reverse-nodes-in-k-group/" target="_blank">LeetCode 25</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Apna College, Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4,5], k = 2, Output: [2,1,4,3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Find length of list. Traverse groups of size k. For each group, perform standard linked list reversal. Link the prev group's tail to the current reversed head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseKGroup(ListNode* head, int k) {&#10;    if(!head || k==1) return head;&#10;    int count = 0; ListNode* dummy = new ListNode(0); dummy-&gt;next = head;&#10;    ListNode *cur = head, *nex, *pre = dummy;&#10;    while(cur) { count++; cur = cur-&gt;next; }&#10;    while(count &gt;= k) {&#10;        cur = pre-&gt;next;&#10;        nex = cur-&gt;next;&#10;        for(int i=1; i&lt;k; i++) {&#10;            cur-&gt;next = nex-&gt;next;&#10;            nex-&gt;next = pre-&gt;next;&#10;            pre-&gt;next = nex;&#10;            nex = cur-&gt;next;&#10;        }&#10;        pre = cur;&#10;        count -= k;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Ll 10 Copy List With Random Pointer<br><br></b> <a href="https://leetcode.com/problems/copy-list-with-random-pointer/" target="_blank">LeetCode 138</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Return a deep copy.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> 3 Steps O(1) space. 1) Insert copy nodes right after original nodes. 2) Set random pointers for copy nodes: `iter->next->random = iter->random ? iter->random->next : NULL`. 3) Separate the two lists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* copyRandomList(Node* head) {&#10;    if(!head) return NULL;&#10;    Node* iter = head;&#10;    while(iter) {&#10;        Node* copy = new Node(iter-&gt;val);&#10;        copy-&gt;next = iter-&gt;next;&#10;        iter-&gt;next = copy;&#10;        iter = copy-&gt;next;&#10;    }&#10;    iter = head;&#10;    while(iter) {&#10;        if(iter-&gt;random) iter-&gt;next-&gt;random = iter-&gt;random-&gt;next;&#10;        iter = iter-&gt;next-&gt;next;&#10;    }&#10;    iter = head; Node* pseudoHead = new Node(0);&#10;    Node* copyIter = pseudoHead;&#10;    while(iter) {&#10;        Node* nextIter = iter-&gt;next-&gt;next;&#10;        copyIter-&gt;next = iter-&gt;next;&#10;        iter-&gt;next = nextIter;&#10;        copyIter = copyIter-&gt;next;&#10;        iter = nextIter;&#10;    }&#10;    return pseudoHead-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Ll 11 Rotate List<br><br></b> <a href="https://leetcode.com/problems/rotate-list/" target="_blank">LeetCode 61</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4,5], k = 2, Output: [4,5,1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Compute the length of the list, and make it a circular list by connecting the last node to head. Then find the new break point `(length - k % length)`. Break the circle and return the new head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* rotateRight(ListNode* head, int k) {&#10;    if(!head || !head-&gt;next || k == 0) return head;&#10;    int len = 1;&#10;    ListNode* cur = head;&#10;    while(cur-&gt;next) {&#10;        len++;&#10;        cur = cur-&gt;next;&#10;    }&#10;    cur-&gt;next = head;&#10;    k = k % len;&#10;    k = len - k;&#10;    while(k--) cur = cur-&gt;next;&#10;    head = cur-&gt;next;&#10;    cur-&gt;next = NULL;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Ll 12 Flattening A Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Recursively merge.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Recursively flatten the `next` list, then merge the current list (`bottom` pointers) with the flattened `next` list, similar to merging two sorted linked lists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* mergeTwoLists(Node* a, Node* b) {&#10;    Node* temp = new Node(0);&#10;    Node* res = temp;&#10;    while(a != NULL &amp;&amp; b != NULL) {&#10;        if(a-&gt;data &lt; b-&gt;data) { temp-&gt;bottom = a; temp = temp-&gt;bottom; a = a-&gt;bottom; }&#10;        else { temp-&gt;bottom = b; temp = temp-&gt;bottom; b = b-&gt;bottom; }&#10;    }&#10;    if(a) temp-&gt;bottom = a;&#10;    else temp-&gt;bottom = b;&#10;    return res-&gt;bottom;&#10;}&#10;Node *flatten(Node *root) {&#10;    if(root == NULL || root-&gt;next == NULL) return root;&#10;    root-&gt;next = flatten(root-&gt;next);&#10;    root = mergeTwoLists(root, root-&gt;next);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Ll 13 Sort A Linked List<br><br></b> <a href="https://leetcode.com/problems/sort-list/" target="_blank">LeetCode 148</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Input: head = [4,2,1,3], Output: [1,2,3,4]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(log N)</td>
      <td><b>Explanation:</b> Merge Sort. Use fast/slow pointers to find the middle of the linked list. Split into two halves, recursively sort both halves, then merge the two sorted halves.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode dummy(0);&#10;    ListNode* tail = &amp;dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) { tail-&gt;next = list1; list1 = list1-&gt;next; }&#10;        else { tail-&gt;next = list2; list2 = list2-&gt;next; }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    return dummy.next;&#10;}&#10;ListNode* sortList(ListNode* head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    ListNode *slow = head, *fast = head-&gt;next;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    ListNode* mid = slow-&gt;next;&#10;    slow-&gt;next = NULL;&#10;    return mergeTwoLists(sortList(head), sortList(mid));&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Ll 14 Find Pairs With Given Sum In Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Two pointer approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Since it is a sorted DLL, set one pointer at the head and one at the tail. If sum == x, add to result and move both. If sum < x, move left pointer next. Else, move right pointer prev.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;pair&lt;int, int&gt;&gt; findPairsWithGivenSum(Node *head, int target) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; ans;&#10;    if(head == NULL) return ans;&#10;    Node* left = head;&#10;    Node* right = head;&#10;    while(right-&gt;next != NULL) right = right-&gt;next;&#10;    while(left != NULL &amp;&amp; right != NULL &amp;&amp; left-&gt;data &lt; right-&gt;data) {&#10;        if(left-&gt;data + right-&gt;data == target) {&#10;            ans.push_back({left-&gt;data, right-&gt;data});&#10;            left = left-&gt;next;&#10;            right = right-&gt;prev;&#10;        } else if(left-&gt;data + right-&gt;data &lt; target) {&#10;            left = left-&gt;next;&#10;        } else {&#10;            right = right-&gt;prev;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Ll 15 Remove Duplicates From Sorted Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Skip duplicates.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse the DLL. While `next` node has the same value, bypass it by updating `curr->next` and `curr->next->prev`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node * removeDuplicates(struct Node *head) {&#10;    Node* curr = head;&#10;    while(curr != NULL) {&#10;        Node* nextNode = curr-&gt;next;&#10;        while(nextNode != NULL &amp;&amp; nextNode-&gt;data == curr-&gt;data) {&#10;            nextNode = nextNode-&gt;next;&#10;        }&#10;        curr-&gt;next = nextNode;&#10;        if(nextNode != NULL) nextNode-&gt;prev = curr;&#10;        curr = curr-&gt;next;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Ll 16 Reverse A Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Swap prev and next.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse the DLL. For each node, swap its `prev` and `next` pointers. The new head will be the last node processed.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* reverseDLL(Node * head) {&#10;    if(head == NULL || head-&gt;next == NULL) return head;&#10;    Node* curr = head;&#10;    Node* temp = NULL;&#10;    while(curr != NULL) {&#10;        temp = curr-&gt;prev;&#10;        curr-&gt;prev = curr-&gt;next;&#10;        curr-&gt;next = temp;&#10;        curr = curr-&gt;prev;&#10;    }&#10;    return temp-&gt;prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Ll 17 Delete All Occurrences Of A Key In Dll<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Update links.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse the list. If `node->data == x`, update the `next` pointer of `node->prev` and `prev` pointer of `node->next`. If the node is head, update head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void deleteAllOccurOfX(struct Node** head_ref, int x) {&#10;    Node* curr = *head_ref;&#10;    while(curr != NULL) {&#10;        if(curr-&gt;data == x) {&#10;            if(curr == *head_ref) *head_ref = curr-&gt;next;&#10;            if(curr-&gt;prev != NULL) curr-&gt;prev-&gt;next = curr-&gt;next;&#10;            if(curr-&gt;next != NULL) curr-&gt;next-&gt;prev = curr-&gt;prev;&#10;            Node* toDelete = curr;&#10;            curr = curr-&gt;next;&#10;            free(toDelete);&#10;        } else {&#10;            curr = curr-&gt;next;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Ll 18 Swap Nodes In Pairs<br><br></b> <a href="https://leetcode.com/problems/swap-nodes-in-pairs/" target="_blank">LeetCode 24</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4], Output: [2,1,4,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use a dummy node. Iteratively swap `curr` and `curr->next`. Keep track of `prev` to link the swapped pairs to the rest of the list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* swapPairs(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    dummy-&gt;next = head;&#10;    ListNode* prev = dummy;&#10;    while(prev-&gt;next != NULL &amp;&amp; prev-&gt;next-&gt;next != NULL) {&#10;        ListNode* first = prev-&gt;next;&#10;        ListNode* second = prev-&gt;next-&gt;next;&#10;        first-&gt;next = second-&gt;next;&#10;        second-&gt;next = first;&#10;        prev-&gt;next = second;&#10;        prev = first;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Ll 19 Odd Even Linked List<br><br></b> <a href="https://leetcode.com/problems/odd-even-linked-list/" target="_blank">LeetCode 328</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Input: head = [1,2,3,4,5], Output: [1,3,5,2,4]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Maintain two pointers `odd` and `even`. Keep the `evenHead`. Loop to link `odd->next = even->next` and `even->next = odd->next`. Finally, link `odd->next = evenHead`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* oddEvenList(ListNode* head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    ListNode *odd = head, *even = head-&gt;next, *evenHead = even;&#10;    while(even &amp;&amp; even-&gt;next) {&#10;        odd-&gt;next = odd-&gt;next-&gt;next;&#10;        even-&gt;next = even-&gt;next-&gt;next;&#10;        odd = odd-&gt;next;&#10;        even = even-&gt;next;&#10;    }&#10;    odd-&gt;next = evenHead;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Ll 20 Split Linked List In Parts<br><br></b> <a href="https://leetcode.com/problems/split-linked-list-in-parts/" target="_blank">LeetCode 725</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Distribution math.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> First, calculate the length of the list. Then, determine base size `len / k` and extra nodes `len % k`. Iterate through the list, breaking it into parts of appropriate sizes.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;ListNode*&gt; splitListToParts(ListNode* head, int k) {&#10;    int len = 0;&#10;    ListNode* curr = head;&#10;    while(curr) { len++; curr = curr-&gt;next; }&#10;    int partSize = len / k, extra = len % k;&#10;    vector&lt;ListNode*&gt; ans;&#10;    curr = head;&#10;    for(int i=0; i&lt;k; i++) {&#10;        ans.push_back(curr);&#10;        int currentPartSize = partSize + (extra &gt; 0 ? 1 : 0);&#10;        extra--;&#10;        for(int j=0; j&lt;currentPartSize - 1; j++) {&#10;            if(curr) curr = curr-&gt;next;&#10;        }&#10;        if(curr) {&#10;            ListNode* nextPart = curr-&gt;next;&#10;            curr-&gt;next = NULL;&#10;            curr = nextPart;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Ll 21 Add Two Numbers Ii<br><br></b> <a href="https://leetcode.com/problems/add-two-numbers-ii/" target="_blank">LeetCode 445</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Stack or reverse.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N + M)</td>
      <td><b>Explanation:</b> Use two stacks to store the digits of the lists. Pop from stacks, add along with carry, and construct the new list by inserting at the head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {&#10;    stack&lt;int&gt; s1, s2;&#10;    while(l1) { s1.push(l1-&gt;val); l1 = l1-&gt;next; }&#10;    while(l2) { s2.push(l2-&gt;val); l2 = l2-&gt;next; }&#10;    int carry = 0;&#10;    ListNode* head = NULL;&#10;    while(!s1.empty() || !s2.empty() || carry) {&#10;        int sum = carry;&#10;        if(!s1.empty()) { sum += s1.top(); s1.pop(); }&#10;        if(!s2.empty()) { sum += s2.top(); s2.pop(); }&#10;        ListNode* node = new ListNode(sum % 10);&#10;        node-&gt;next = head;&#10;        head = node;&#10;        carry = sum / 10;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Ll 22 Insertion Sort List<br><br></b> <a href="https://leetcode.com/problems/insertion-sort-list/" target="_blank">LeetCode 147</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Dummy head.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use a dummy head for the sorted part. For each node in the original list, iterate through the sorted part to find its correct position and insert it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* insertionSortList(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* curr = head;&#10;    while(curr) {&#10;        ListNode* prev = dummy;&#10;        while(prev-&gt;next &amp;&amp; prev-&gt;next-&gt;val &lt;= curr-&gt;val) {&#10;            prev = prev-&gt;next;&#10;        }&#10;        ListNode* next = curr-&gt;next;&#10;        curr-&gt;next = prev-&gt;next;&#10;        prev-&gt;next = curr;&#10;        curr = next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Ll 23 Partition List<br><br></b> <a href="https://leetcode.com/problems/partition-list/" target="_blank">LeetCode 86</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Two lists then join.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Maintain two separate linked lists: `before` and `after` with their own dummy heads. Iterate through original list, appending to `before` or `after` based on value. Then link `before` tail to `after` head.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* partition(ListNode* head, int x) {&#10;    ListNode* before_head = new ListNode(0);&#10;    ListNode* before = before_head;&#10;    ListNode* after_head = new ListNode(0);&#10;    ListNode* after = after_head;&#10;    while(head) {&#10;        if(head-&gt;val &lt; x) {&#10;            before-&gt;next = head;&#10;            before = before-&gt;next;&#10;        } else {&#10;            after-&gt;next = head;&#10;            after = after-&gt;next;&#10;        }&#10;        head = head-&gt;next;&#10;    }&#10;    after-&gt;next = NULL;&#10;    before-&gt;next = after_head-&gt;next;&#10;    return before_head-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Ll 24 Reverse Nodes In Even Length Groups<br><br></b> <a href="https://leetcode.com/problems/reverse-nodes-in-even-length-groups/" target="_blank">LeetCode 2074</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Group tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse the list while tracking the expected group length. First, count the actual number of nodes left in the current group. If the count is even, reverse this sublist and connect it to the previous part. If odd, just skip. Update lengths and pointers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseEvenLengthGroups(ListNode* head) {&#10;    int groupLen = 1;&#10;    ListNode* prev = nullptr;&#10;    ListNode* curr = head;&#10;    while(curr != nullptr) {&#10;        ListNode* temp = curr;&#10;        int count = 0;&#10;        while(count &lt; groupLen &amp;&amp; temp != nullptr) {&#10;            temp = temp-&gt;next;&#10;            count++;&#10;        }&#10;        if(count % 2 == 0) {&#10;            ListNode* groupPrev = nullptr;&#10;            ListNode* groupCurr = curr;&#10;            ListNode* nextNode = nullptr;&#10;            for(int i=0; i&lt;count; i++) {&#10;                nextNode = groupCurr-&gt;next;&#10;                groupCurr-&gt;next = groupPrev;&#10;                groupPrev = groupCurr;&#10;                groupCurr = nextNode;&#10;            }&#10;            prev-&gt;next = groupPrev;&#10;            curr-&gt;next = groupCurr;&#10;            prev = curr;&#10;            curr = groupCurr;&#10;        } else {&#10;            for(int i=0; i&lt;count; i++) {&#10;                prev = curr;&#10;                curr = curr-&gt;next;&#10;            }&#10;        }&#10;        groupLen++;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Ll 25 Swapping Nodes In A Linked List<br><br></b> <a href="https://leetcode.com/problems/swapping-nodes-in-a-linked-list/" target="_blank">LeetCode 1721</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Two passes or three pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use two pointers. Move `fast` pointer `k-1` steps. `first_node` is at `fast`. Initialize `slow = head`. Move both `slow` and `fast` to the end. `slow` will be at `second_node`. Swap values.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* swapNodes(ListNode* head, int k) {&#10;    ListNode* fast = head;&#10;    for(int i=1; i&lt;k; i++) fast = fast-&gt;next;&#10;    ListNode* firstNode = fast;&#10;    ListNode* slow = head;&#10;    while(fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next;&#10;    }&#10;    swap(firstNode-&gt;val, slow-&gt;val);&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Ll 26 Merge Nodes In Between Zeros<br><br></b> <a href="https://leetcode.com/problems/merge-nodes-in-between-zeros/" target="_blank">LeetCode 2181</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Accumulate and connect.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) extra space if we modify in-place</td>
      <td><b>Explanation:</b> Maintain a dummy node. Traverse the list. Maintain a running sum. When we encounter a 0 (and sum > 0), create a new node with `sum`, attach it to dummy list, reset `sum` to 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeNodes(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* currDummy = dummy;&#10;    ListNode* curr = head-&gt;next;&#10;    int sum = 0;&#10;    while(curr) {&#10;        if(curr-&gt;val == 0) {&#10;            currDummy-&gt;next = new ListNode(sum);&#10;            currDummy = currDummy-&gt;next;&#10;            sum = 0;&#10;        } else {&#10;            sum += curr-&gt;val;&#10;        }&#10;        curr = curr-&gt;next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Ll 27 Design Hashmap<br><br></b> <a href="https://leetcode.com/problems/design-hashmap/" target="_blank">LeetCode 706</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Array of Linked Lists with Key-Value pairs.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(Number of elements)</td>
      <td><b>Explanation:</b> Similar to HashSet, but each node stores a `(key, value)` pair. On Put, if key exists, update value. Else insert new node. On Get, return value if key found, else -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MyHashMap {&#10;    struct Node {&#10;        int key, val;&#10;        Node* next;&#10;        Node(int k, int v): key(k), val(v), next(nullptr) {}&#10;    };&#10;    vector&lt;Node*&gt; buckets;&#10;    int size = 10007;&#10;public:&#10;    MyHashMap() {&#10;        buckets.assign(size, nullptr);&#10;    }&#10;    void put(int key, int value) {&#10;        int idx = key % size;&#10;        Node* curr = buckets[idx];&#10;        while(curr) {&#10;            if(curr-&gt;key == key) { curr-&gt;val = value; return; }&#10;            curr = curr-&gt;next;&#10;        }&#10;        Node* newNode = new Node(key, value);&#10;        newNode-&gt;next = buckets[idx];&#10;        buckets[idx] = newNode;&#10;    }&#10;    int get(int key) {&#10;        int idx = key % size;&#10;        Node* curr = buckets[idx];&#10;        while(curr) {&#10;            if(curr-&gt;key == key) return curr-&gt;val;&#10;            curr = curr-&gt;next;&#10;        }&#10;        return -1;&#10;    }&#10;    void remove(int key) {&#10;        int idx = key % size;&#10;        Node* curr = buckets[idx];&#10;        Node* prev = nullptr;&#10;        while(curr) {&#10;            if(curr-&gt;key == key) {&#10;                if(prev) prev-&gt;next = curr-&gt;next;&#10;                else buckets[idx] = curr-&gt;next;&#10;                delete curr;&#10;                return;&#10;            }&#10;            prev = curr;&#10;            curr = curr-&gt;next;&#10;        }&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Ll 28 Design Browser History<br><br></b> <a href="https://leetcode.com/problems/design-browser-history/" target="_blank">LeetCode 1472</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Doubly Linked List.</td>
      <td><b>Time:</b> O(1) visit, O(steps) back/forward<br><b>Space:</b> O(N) for URLs</td>
      <td><b>Explanation:</b> Use a Doubly Linked List. Each visit creates a new node, clearing forward history. Back and forward operations just traverse the pointers up to `steps` times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BrowserHistory {&#10;    struct Node {&#10;        string url;&#10;        Node *prev, *next;&#10;        Node(string u): url(u), prev(nullptr), next(nullptr) {}&#10;    };&#10;    Node* curr;&#10;public:&#10;    BrowserHistory(string homepage) {&#10;        curr = new Node(homepage);&#10;    }&#10;    void visit(string url) {&#10;        Node* newNode = new Node(url);&#10;        curr-&gt;next = newNode;&#10;        newNode-&gt;prev = curr;&#10;        curr = newNode;&#10;    }&#10;    string back(int steps) {&#10;        while(steps &gt; 0 &amp;&amp; curr-&gt;prev) {&#10;            curr = curr-&gt;prev;&#10;            steps--;&#10;        }&#10;        return curr-&gt;url;&#10;    }&#10;    string forward(int steps) {&#10;        while(steps &gt; 0 &amp;&amp; curr-&gt;next) {&#10;            curr = curr-&gt;next;&#10;            steps--;&#10;        }&#10;        return curr-&gt;url;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Ll 29 Lru Cache Ll<br><br></b> <a href="https://leetcode.com/problems/lru-cache/" target="_blank">LeetCode 146</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Duplicate logic entry to ensure coverage.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Included for chapter coverage completeness. See sq_31_lru_cache.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// See Stacks and Queues module for full implementation.</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Ll 30 Lfu Cache Ll<br><br></b> <a href="https://leetcode.com/problems/lfu-cache/" target="_blank">LeetCode 460</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Duplicate logic entry to ensure coverage.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Included for chapter coverage completeness. See sq_32_lfu_cache.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// See Stacks and Queues module for full implementation.</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Ll 31 All Oone Data Structure<br><br></b> <a href="https://leetcode.com/problems/all-oone-data-structure/" target="_blank">LeetCode 432</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Doubly linked list of frequency buckets.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Maintain a DLL where each node represents a specific frequency and contains a set of strings. Use a hash map mapping strings to their current bucket. On inc/dec, move the string to the adjacent bucket (create if necessary). Max is tail->prev, Min is head->next.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class AllOne {&#10;    struct Bucket {&#10;        int count;&#10;        unordered_set&lt;string&gt; keys;&#10;        Bucket *prev, *next;&#10;        Bucket(int c): count(c), prev(nullptr), next(nullptr) {}&#10;    };&#10;    Bucket *head, *tail;&#10;    unordered_map&lt;string, Bucket*&gt; m;&#10;    void addBucket(Bucket* prev, Bucket* newBucket) {&#10;        newBucket-&gt;prev = prev;&#10;        newBucket-&gt;next = prev-&gt;next;&#10;        prev-&gt;next-&gt;prev = newBucket;&#10;        prev-&gt;next = newBucket;&#10;    }&#10;    void removeBucket(Bucket* bucket) {&#10;        bucket-&gt;prev-&gt;next = bucket-&gt;next;&#10;        bucket-&gt;next-&gt;prev = bucket-&gt;prev;&#10;        delete bucket;&#10;    }&#10;public:&#10;    AllOne() {&#10;        head = new Bucket(0); tail = new Bucket(0);&#10;        head-&gt;next = tail; tail-&gt;prev = head;&#10;    }&#10;    void inc(string key) {&#10;        if(m.find(key) != m.end()) {&#10;            Bucket* curr = m[key];&#10;            Bucket* nxt = curr-&gt;next;&#10;            if(nxt == tail || nxt-&gt;count != curr-&gt;count + 1) {&#10;                addBucket(curr, new Bucket(curr-&gt;count + 1));&#10;                nxt = curr-&gt;next;&#10;            }&#10;            nxt-&gt;keys.insert(key);&#10;            m[key] = nxt;&#10;            curr-&gt;keys.erase(key);&#10;            if(curr-&gt;keys.empty()) removeBucket(curr);&#10;        } else {&#10;            Bucket* nxt = head-&gt;next;&#10;            if(nxt == tail || nxt-&gt;count != 1) {&#10;                addBucket(head, new Bucket(1));&#10;                nxt = head-&gt;next;&#10;            }&#10;            nxt-&gt;keys.insert(key);&#10;            m[key] = nxt;&#10;        }&#10;    }&#10;    void dec(string key) {&#10;        Bucket* curr = m[key];&#10;        if(curr-&gt;count == 1) {&#10;            m.erase(key);&#10;        } else {&#10;            Bucket* prv = curr-&gt;prev;&#10;            if(prv == head || prv-&gt;count != curr-&gt;count - 1) {&#10;                addBucket(curr-&gt;prev, new Bucket(curr-&gt;count - 1));&#10;                prv = curr-&gt;prev;&#10;            }&#10;            prv-&gt;keys.insert(key);&#10;            m[key] = prv;&#10;        }&#10;        curr-&gt;keys.erase(key);&#10;        if(curr-&gt;keys.empty()) removeBucket(curr);&#10;    }&#10;    string getMaxKey() {&#10;        if(tail-&gt;prev == head) return &quot;&quot;;&#10;        return *(tail-&gt;prev-&gt;keys.begin());&#10;    }&#10;    string getMinKey() {&#10;        if(head-&gt;next == tail) return &quot;&quot;;&#10;        return *(head-&gt;next-&gt;keys.begin());&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Ll 32 Flatten A Multilevel Doubly Linked List<br><br></b> <a href="https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/" target="_blank">LeetCode 430</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** DFS / Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Iterate through the list. When a node has a child, find the tail of the child list. Connect the tail to `node->next`, and `node->next` to the child. Update `prev` pointers. Set `node->child` to `nullptr`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">/*&#10;// Definition for a Node.&#10;class Node {&#10;public:&#10;    int val;&#10;    Node* prev;&#10;    Node* next;&#10;    Node* child;&#10;};&#10;*/&#10;Node* flatten(Node* head) {&#10;    if(!head) return nullptr;&#10;    Node* curr = head;&#10;    while(curr) {&#10;        if(curr-&gt;child) {&#10;            Node* tail = curr-&gt;child;&#10;            while(tail-&gt;next) tail = tail-&gt;next;&#10;            tail-&gt;next = curr-&gt;next;&#10;            if(curr-&gt;next) curr-&gt;next-&gt;prev = tail;&#10;            curr-&gt;next = curr-&gt;child;&#10;            curr-&gt;child-&gt;prev = curr;&#10;            curr-&gt;child = nullptr;&#10;        }&#10;        curr = curr-&gt;next;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Ll 33 Delete Nodes Having Greater Value On Right<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Reverse, filter, reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Reverse the linked list. Traverse the reversed list and keep track of the maximum value seen so far. If a node's value is less than the maximum, delete it. Otherwise, update the maximum. Finally, reverse the list again.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* reverseList(Node* head) {&#10;    Node* prev = NULL, *curr = head, *next = NULL;&#10;    while(curr) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;    }&#10;    return prev;&#10;}&#10;Node *compute(Node *head) {&#10;    head = reverseList(head);&#10;    Node* curr = head;&#10;    int max_val = head-&gt;data;&#10;    while(curr &amp;&amp; curr-&gt;next) {&#10;        if(curr-&gt;next-&gt;data &lt; max_val) {&#10;            Node* temp = curr-&gt;next;&#10;            curr-&gt;next = temp-&gt;next;&#10;            delete temp;&#10;        } else {&#10;            curr = curr-&gt;next;&#10;            max_val = curr-&gt;data;&#10;        }&#10;    }&#10;    return reverseList(head);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Ll 34 Reverse A Linked List In Groups Of Given Size<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Recursive grouping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N/K)</td>
      <td><b>Explanation:</b> Reverse the first `k` nodes of the linked list iteratively. After reversing, the `head` pointer will be the end of the reversed group, and `curr` will point to the next node. Recursively call the function for `curr` and set `head->next` to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct node *reverse (struct node *head, int k) {&#10;    if(!head) return NULL;&#10;    struct node* curr = head, *prev = NULL, *next = NULL;&#10;    int count = 0;&#10;    while(curr &amp;&amp; count &lt; k) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;        count++;&#10;    }&#10;    if(next) head-&gt;next = reverse(next, k);&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Ll 35 Find The First Node Of Loop In Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Floyd's Cycle Detection.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use Floyd's Cycle Detection to find if a cycle exists (slow and fast pointers meet). Then, move slow back to head, and advance both slow and fast by one step until they meet. The meeting point is the start of the loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findFirstNode(Node* head) {&#10;    Node *slow = head, *fast = head;&#10;    while(fast != NULL &amp;&amp; fast-&gt;next != NULL) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) {&#10;            slow = head;&#10;            while(slow != fast) {&#10;                slow = slow-&gt;next;&#10;                fast = fast-&gt;next;&#10;            }&#10;            return slow-&gt;data;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Ll 36 Detect Loop In Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td>**Example 1:** Floyd's Cycle Detection.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use Floyd's Cycle Detection algorithm (Tortoise and Hare). Move `slow` by 1 and `fast` by 2. If they meet, a loop exists. If `fast` reaches NULL, there is no loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool detectLoop(Node* head) {&#10;    Node* slow = head, *fast = head;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Ll 37 Add Two Numbers Represented By Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td>**Example 1:** Reverse, Add, Reverse.</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td><b>Explanation:</b> Reverse both linked lists. Traverse both lists simultaneously, adding the data values of corresponding nodes along with the carry. Create new nodes for the sum and append them to the result list. Finally, reverse the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node* reverse(struct Node* head) {&#10;    Node* prev = NULL, *curr = head, *next = NULL;&#10;    while(curr) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;    }&#10;    return prev;&#10;}&#10;struct Node* addTwoLists(struct Node* first, struct Node* second) {&#10;    first = reverse(first);&#10;    second = reverse(second);&#10;    Node* dummy = new Node(0), *temp = dummy;&#10;    int carry = 0;&#10;    while(first || second || carry) {&#10;        int sum = carry;&#10;        if(first) { sum += first-&gt;data; first = first-&gt;next; }&#10;        if(second) { sum += second-&gt;data; second = second-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new Node(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return reverse(dummy-&gt;next);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Ll 38 Intersection Point In Y Shaped Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td>**Example 1:** Two Pointers.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use two pointers `a` and `b`. Traverse both lists. When `a` reaches the end, redirect it to `head2`. When `b` reaches the end, redirect it to `head1`. They will meet at the intersection point or both become NULL.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int intersectPoint(Node* head1, Node* head2) {&#10;    Node* a = head1, *b = head2;&#10;    while(a != b) {&#10;        a = (a) ? a-&gt;next : head2;&#10;        b = (b) ? b-&gt;next : head1;&#10;    }&#10;    if(a) return a-&gt;data;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
