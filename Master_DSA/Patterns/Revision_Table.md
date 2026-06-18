# Patterns Revision Table

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
      <td>1</td>
      <td>Pattern 1 Rectangular Star</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;***&#10;***&#10;***&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*****&#10;*****&#10;*****&#10;*****&#10;*****</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n; j++) {&#10;            cout &lt;&lt; &quot;*&quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Pattern 2 Right Angled Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*&#10;**&#10;***&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*&#10;**&#10;***&#10;****&#10;*****</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; &quot;* &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Pattern 3 Right Angled Number Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;1 2&#10;1 2 3&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1&#10;1 2&#10;1 2 3&#10;1 2 3 4&#10;1 2 3 4 5</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; j &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Pattern 4 Right Angled Number Pyramid Ii</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;2 2&#10;3 3 3&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1&#10;2 2&#10;3 3 3&#10;4 4 4 4&#10;5 5 5 5 5</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; i &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Pattern 5 Inverted Right Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;* * *&#10;* *&#10;*&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;* * * * *&#10;* * * *&#10;* * *&#10;* *&#10;*</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; n - i + 1; j++) {&#10;            cout &lt;&lt; &quot;* &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Pattern 6 Inverted Numbered Right Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1 2 3&#10;1 2&#10;1&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1 2 3 4 5&#10;1 2 3 4&#10;1 2 3&#10;1 2&#10;1</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n - i + 1; j++) {&#10;            cout &lt;&lt; j &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Pattern 7 Star Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;  *&#10; ***&#10;*****&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;    *&#10;   ***&#10;  *****&#10; *******&#10;*********</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * i + 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Pattern 8 Inverted Star Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*****&#10; ***&#10;  *&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*********&#10; *******&#10;  *****&#10;   ***&#10;    *</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * (n - i) - 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Pattern 9 Diamond Star Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;  *&#10; ***&#10;*****&#10;*****&#10; ***&#10;  *&#10;</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * i + 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * (n - i) - 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Pattern 10 Half Diamond Star Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*&#10;**&#10;***&#10;**&#10;*&#10;</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 1; i &lt;= 2*n-1; i++) {&#10;        int stars = i;&#10;        if(i &gt; n) stars = 2*n - i;&#10;        for(int j = 1; j &lt;= stars; j++) {&#10;            cout &lt;&lt; &quot;*&quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    int n = 5;&#10;    printPattern(n);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Pattern 11 Binary Number Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;0 1&#10;1 0 1&#10;</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    int start = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) start = 1;&#10;        else start = 0;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; start &lt;&lt; &quot; &quot;;&#10;            start = 1 - start;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Pattern 12 Number Crown Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1    1&#10;12  21&#10;123321</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    int space = 2 * (n - 1);&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; j;&#10;        for(int j = 1; j &lt;= space; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = i; j &gt;= 1; j--) cout &lt;&lt; j;&#10;        cout &lt;&lt; endl;&#10;        space -= 2;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Pattern 13 Increasing Number Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;2 3&#10;4 5 6</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    int num = 1;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; num &lt;&lt; &quot; &quot;;&#10;            num++;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Pattern 14 Increasing Letter Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;A&#10;A B&#10;A B C</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27;; ch &lt;= &#x27;A&#x27; + i; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Pattern 15 Reverse Letter Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;A B C&#10;A B&#10;A</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27;; ch &lt; &#x27;A&#x27; + n - i; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Pattern 16 Alpha Ramp Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;A&#10;B B&#10;C C C</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        char ch = &#x27;A&#x27; + i;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Pattern 17 Alpha Hill Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;  A&#10; ABA&#10;ABCBA</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        char ch = &#x27;A&#x27;;&#10;        int breakpoint = (2 * i + 1) / 2;&#10;        for(int j = 1; j &lt;= 2 * i + 1; j++) {&#10;            cout &lt;&lt; ch;&#10;            if(j &lt;= breakpoint) ch++;&#10;            else ch--;&#10;        }&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Pattern 18 Alpha Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;C&#10;C B&#10;C B A</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27; + n - 1 - i; ch &lt;= &#x27;A&#x27; + n - 1; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Pattern 19 Symmetric Void Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;******&#10;**  **&#10;*    *&#10;*    *&#10;**  **&#10;******</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    int iniSpace = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 1; j &lt;= n - i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; iniSpace; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= n - i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        iniSpace += 2;&#10;        cout &lt;&lt; endl;&#10;    }&#10;    iniSpace = 2 * n - 2;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; iniSpace; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        iniSpace -= 2;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Pattern 20 Symmetric Butterfly Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*    *&#10;**  **&#10;******&#10;**  **&#10;*    *</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    int spaces = 2 * n - 2;&#10;    for(int i = 1; i &lt;= 2 * n - 1; i++) {&#10;        int stars = i;&#10;        if(i &gt; n) stars = 2 * n - i;&#10;        for(int j = 1; j &lt;= stars; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 1; j &lt;= spaces; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= stars; j++) cout &lt;&lt; &quot;*&quot;;&#10;        cout &lt;&lt; endl;&#10;        if(i &lt; n) spaces -= 2;&#10;        else spaces += 2;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Pattern 21 Hollow Rectangle Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;***&#10;* *&#10;***</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n; j++) {&#10;            if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {&#10;                cout &lt;&lt; &quot;*&quot;;&#10;            } else {&#10;                cout &lt;&lt; &quot; &quot;;&#10;            }&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(5);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Pattern 22 The Number Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;3 3 3 3 3&#10;3 2 2 2 3&#10;3 2 1 2 3&#10;3 2 2 2 3&#10;3 3 3 3 3</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><b>Time:</b> O(N<sup>2</sup>)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Grid print restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;iostream&gt;&#10;#include &lt;algorithm&gt;&#10;using namespace std;&#10;&#10;void printPattern(int n) {&#10;    for(int i = 0; i &lt; 2 * n - 1; i++) {&#10;        for(int j = 0; j &lt; 2 * n - 1; j++) {&#10;            int top = i;&#10;            int left = j;&#10;            int right = (2 * n - 2) - j;&#10;            int down = (2 * n - 2) - i;&#10;            cout &lt;&lt; (n - min({top, left, right, down})) &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}&#10;&#10;int main() {&#10;    printPattern(4);&#10;    return 0;&#10;}&#10;</code></pre></details></td>
    </tr>
  </tbody>
</table>
