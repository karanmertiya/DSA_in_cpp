# Apna College - Patterns Revision Table

<table border="1">
  <thead>
    <tr>
      <th>S.No</th>
      <th>Problem Name</th>
      <th>Example</th>
      <th>Common Constraints</th>
      <th>Approach Type</th>
      <th>Time</th>
      <th>Space</th>
      <th>Specific Conditions / Edge Cases</th>
      <th>Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Pattern 01 Rectangular Star</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;***&#10;***&#10;***&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*****&#10;*****&#10;*****&#10;*****&#10;*****</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n; j++) {&#10;            cout &lt;&lt; &quot;*&quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>2</td>
      <td>Pattern 02 Right Angled Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;*&#10;**&#10;***&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*&#10;**&#10;***&#10;****&#10;*****</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; &quot;* &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>3</td>
      <td>Pattern 03 Right Angled Number Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;1 2&#10;1 2 3&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1&#10;1 2&#10;1 2 3&#10;1 2 3 4&#10;1 2 3 4 5</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; j &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>4</td>
      <td>Pattern 04 Right Angled Number Pyramid Ii</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;2 2&#10;3 3 3&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1&#10;2 2&#10;3 3 3&#10;4 4 4 4&#10;5 5 5 5 5</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; i &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>5</td>
      <td>Pattern 05 Inverted Right Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;* * *&#10;* *&#10;*&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;* * * * *&#10;* * * *&#10;* * *&#10;* *&#10;*</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; n - i + 1; j++) {&#10;            cout &lt;&lt; &quot;* &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>6</td>
      <td>Pattern 06 Inverted Numbered Right Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;1 2 3&#10;1 2&#10;1&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1 2 3 4 5&#10;1 2 3 4&#10;1 2 3&#10;1 2&#10;1</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n - i + 1; j++) {&#10;            cout &lt;&lt; j &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>7</td>
      <td>Pattern 07 Star Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;  *&#10; ***&#10;*****&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;    *&#10;   ***&#10;  *****&#10; *******&#10;*********</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * i + 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>8</td>
      <td>Pattern 08 Inverted Star Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;*****&#10; ***&#10;  *&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*********&#10; *******&#10;  *****&#10;   ***&#10;    *</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * (n - i) - 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>9</td>
      <td>Pattern 09 Diamond Star Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;  *&#10; ***&#10;*****&#10;*****&#10; ***&#10;  *&#10;</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * i + 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * (n - i) - 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>10</td>
      <td>Pattern 10 Half Diamond Star Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;*&#10;**&#10;***&#10;**&#10;*&#10;</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= 2*n-1; i++) {&#10;        int stars = i;&#10;        if(i &gt; n) stars = 2*n - i;&#10;        for(int j = 1; j &lt;= stars; j++) {&#10;            cout &lt;&lt; &quot;*&quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>11</td>
      <td>Pattern 21 Hollow Rectangle Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;***&#10;* *&#10;***</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n; j++) {&#10;            if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {&#10;                cout &lt;&lt; &quot;*&quot;;&#10;            } else {&#10;                cout &lt;&lt; &quot; &quot;;&#10;            }&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
  </tbody>
</table>
