# Day 28 29 Tries Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 20%;">Example & Constraints</th>
      <th style="width: 10%;">Complexity</th>
      <th style="width: 20%;">Approach & Dependencies</th>
      <th style="width: 30%;">Logic & Edge Cases</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="1">1</td>
      <td rowspan="1">Trie 01 Implement Trie Prefix Tree<br><br></b> <a href="https://leetcode.com/problems/implement-trie-prefix-tree/" target="_blank">LeetCode 208</a></td>
      <td rowspan="1"><b>Example 1:</b> `insert("apple")`, `search("apple")` -> true, `search("app")` -> false, `startsWith("app")` -> true.<br><br><b>Note (Constraint):</b> 1 &le; word.length &le; 2000, lowercase English letters.</td>
      <td><b>Time:</b> O(Length of word) (Constraint)<br><b>Space:</b> O(Length * 26) per word</td>
      <td>Use a Tree where each node contains an array of 26 pointers (for 'a'-'z') and a boolean flag `isEnd`.<br><br><b>Dependencies:</b> Custom Node Struct/Class</td>
      <td><b>Edge Cases:</b> <b>startsWith vs search:</b> `startsWith` returns true simply if the traversal succeeds without hitting NULL. `search` requires the final node's `isEnd` flag to be true.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    bool flag = false;&#10;    bool containsKey(char ch) { return (links[ch - &#x27;a&#x27;] != nullptr); }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void setEnd() { flag = true; }&#10;    bool isEnd() { return flag; }&#10;};&#10;&#10;class Trie {&#10;private:&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    &#10;    void insert(std::string word) {&#10;        Node* node = root;&#10;        for (char ch : word) {&#10;            if (!node-&gt;containsKey(ch)) {&#10;                node-&gt;put(ch, new Node());&#10;            }&#10;            node = node-&gt;get(ch);&#10;        }&#10;        node-&gt;setEnd();&#10;    }&#10;    &#10;    bool search(std::string word) {&#10;        Node* node = root;&#10;        for (char ch : word) {&#10;            if (!node-&gt;containsKey(ch)) return false;&#10;            node = node-&gt;get(ch);&#10;        }&#10;        return node-&gt;isEnd();&#10;    }&#10;    &#10;    bool startsWith(std::string prefix) {&#10;        Node* node = root;&#10;        for (char ch : prefix) {&#10;            if (!node-&gt;containsKey(ch)) return false;&#10;            node = node-&gt;get(ch);&#10;        }&#10;        return true;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Trie 02 Implement Trie II<br><br></b> <a href="https://www.codingninjas.com/studio/problems/implement-trie_1387095" target="_blank">Coding Ninjas</a></td>
      <td rowspan="1"><b>Example 1:</b> Specialized Trie functions.</td>
      <td><b>Time:</b> O(len) per operation<br><b>Space:</b> O(N * len)</td>
      <td>Trie Nodes have a `cntEndWith` and `cntPrefix` integers. Increment `cntPrefix` dynamically as you insert, and `cntEndWith` at the final node. Decrement them during erase.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    int cntEndWith = 0;&#10;    int cntPrefix = 0;&#10;    bool containsKey(char ch) { return links[ch - &#x27;a&#x27;] != NULL; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    void increaseEnd() { cntEndWith++; }&#10;    void increasePrefix() { cntPrefix++; }&#10;    void deleteEnd() { cntEndWith--; }&#10;    void reducePrefix() { cntPrefix--; }&#10;};&#10;class Trie {&#10;private: Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(!node-&gt;containsKey(word[i])) node-&gt;put(word[i], new Node());&#10;            node = node-&gt;get(word[i]);&#10;            node-&gt;increasePrefix();&#10;        }&#10;        node-&gt;increaseEnd();&#10;    }&#10;    int countWordsEqualTo(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(node-&gt;containsKey(word[i])) node = node-&gt;get(word[i]);&#10;            else return 0;&#10;        }&#10;        return node-&gt;cntEndWith;&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>
