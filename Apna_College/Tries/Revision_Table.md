# Tries Revision Table

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
      <td rowspan="1">Trie 01 Implement Trie Prefix Tree<br><br></b> <a href='https://leetcode.com/problems/implement-trie-prefix-tree/' target='_blank'>LeetCode 208</a></td>
      <td rowspan="1"><b>Example 1:</b> `insert("apple")`, `search("apple")` -> true, `search("app")` -> false, `startsWith("app")` -> true.<br><br><b>Note (Constraint):</b> 1 &le; word.length &le; 2000, lowercase English letters.</td>
      <td><b>Time:</b> O(Length of word) (Constraint)<br><b>Space:</b> O(Length * 26) per word</td>
      <td>Custom Node Struct/Class</td>
      <td><b>startsWith vs search:</b> `startsWith` returns true simply if the traversal succeeds without hitting NULL. `search` requires the final node's `isEnd` flag to be true.</td>
      <td><b>Explanation:</b> Use a Tree where each node contains an array of 26 pointers (for 'a'-'z') and a boolean flag `isEnd`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    bool flag = false;&#10;    bool containsKey(char ch) { return (links[ch - &#x27;a&#x27;] != nullptr); }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void setEnd() { flag = true; }&#10;    bool isEnd() { return flag; }&#10;};&#10;&#10;class Trie {&#10;private:&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    &#10;    void insert(std::string word) {&#10;        Node* node = root;&#10;        for (char ch : word) {&#10;            if (!node-&gt;containsKey(ch)) {&#10;                node-&gt;put(ch, new Node());&#10;            }&#10;            node = node-&gt;get(ch);&#10;        }&#10;        node-&gt;setEnd();&#10;    }&#10;    &#10;    bool search(std::string word) {&#10;        Node* node = root;&#10;        for (char ch : word) {&#10;            if (!node-&gt;containsKey(ch)) return false;&#10;            node = node-&gt;get(ch);&#10;        }&#10;        return node-&gt;isEnd();&#10;    }&#10;    &#10;    bool startsWith(std::string prefix) {&#10;        Node* node = root;&#10;        for (char ch : prefix) {&#10;            if (!node-&gt;containsKey(ch)) return false;&#10;            node = node-&gt;get(ch);&#10;        }&#10;        return true;&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>
