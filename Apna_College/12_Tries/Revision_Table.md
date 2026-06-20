# 12 Tries Revision Table

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
      <td>Trie 01 Implement Trie Ii<br><br></b> <a href="https://www.codingninjas.com/studio/problems/implement-trie_1387095" target="_blank">Coding Ninjas</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td><b>Example 1:</b> Specialized Trie functions.</td>
      <td><b>Time:</b> O(len) per operation<br><b>Space:</b> O(N * len)</td>
      <td><b>Explanation:</b> Trie Nodes have a `cntEndWith` and `cntPrefix` integers. Increment `cntPrefix` dynamically as you insert, and `cntEndWith` at the final node. Decrement them during erase.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    int cntEndWith = 0;&#10;    int cntPrefix = 0;&#10;    bool containsKey(char ch) { return links[ch - &#x27;a&#x27;] != NULL; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    void increaseEnd() { cntEndWith++; }&#10;    void increasePrefix() { cntPrefix++; }&#10;    void deleteEnd() { cntEndWith--; }&#10;    void reducePrefix() { cntPrefix--; }&#10;};&#10;class Trie {&#10;private: Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(!node-&gt;containsKey(word[i])) node-&gt;put(word[i], new Node());&#10;            node = node-&gt;get(word[i]);&#10;            node-&gt;increasePrefix();&#10;        }&#10;        node-&gt;increaseEnd();&#10;    }&#10;    int countWordsEqualTo(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(node-&gt;containsKey(word[i])) node = node-&gt;get(word[i]);&#10;            else return 0;&#10;        }&#10;        return node-&gt;cntEndWith;&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>
