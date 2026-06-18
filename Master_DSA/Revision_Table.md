# Master DSA - Global Revision Table

## Patterns

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
      <td>Pattern 11 Binary Number Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;0 1&#10;1 0 1&#10;</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int start = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) start = 1;&#10;        else start = 0;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; start &lt;&lt; &quot; &quot;;&#10;            start = 1 - start;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>12</td>
      <td>Pattern 12 Number Crown Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;1    1&#10;12  21&#10;123321</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int space = 2 * (n - 1);&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; j;&#10;        for(int j = 1; j &lt;= space; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = i; j &gt;= 1; j--) cout &lt;&lt; j;&#10;        cout &lt;&lt; endl;&#10;        space -= 2;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>13</td>
      <td>Pattern 13 Increasing Number Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;2 3&#10;4 5 6</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int num = 1;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; num &lt;&lt; &quot; &quot;;&#10;            num++;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>14</td>
      <td>Pattern 14 Increasing Letter Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;A&#10;A B&#10;A B C</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27;; ch &lt;= &#x27;A&#x27; + i; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>15</td>
      <td>Pattern 15 Reverse Letter Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;A B C&#10;A B&#10;A</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27;; ch &lt; &#x27;A&#x27; + n - i; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>16</td>
      <td>Pattern 16 Alpha Ramp Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;A&#10;B B&#10;C C C</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        char ch = &#x27;A&#x27; + i;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>17</td>
      <td>Pattern 17 Alpha Hill Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;  A&#10; ABA&#10;ABCBA</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        char ch = &#x27;A&#x27;;&#10;        int breakpoint = (2 * i + 1) / 2;&#10;        for(int j = 1; j &lt;= 2 * i + 1; j++) {&#10;            cout &lt;&lt; ch;&#10;            if(j &lt;= breakpoint) ch++;&#10;            else ch--;&#10;        }&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>18</td>
      <td>Pattern 18 Alpha Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;C&#10;C B&#10;C B A</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27; + n - 1 - i; ch &lt;= &#x27;A&#x27; + n - 1; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>19</td>
      <td>Pattern 19 Symmetric Void Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;******&#10;**  **&#10;*    *&#10;*    *&#10;**  **&#10;******</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int iniSpace = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 1; j &lt;= n - i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; iniSpace; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= n - i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        iniSpace += 2;&#10;        cout &lt;&lt; endl;&#10;    }&#10;    iniSpace = 2 * n - 2;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; iniSpace; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        iniSpace -= 2;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>20</td>
      <td>Pattern 20 Symmetric Butterfly Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;*    *&#10;**  **&#10;******&#10;**  **&#10;*    *</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int spaces = 2 * n - 2;&#10;    for(int i = 1; i &lt;= 2 * n - 1; i++) {&#10;        int stars = i;&#10;        if(i &gt; n) stars = 2 * n - i;&#10;        for(int j = 1; j &lt;= stars; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 1; j &lt;= spaces; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= stars; j++) cout &lt;&lt; &quot;*&quot;;&#10;        cout &lt;&lt; endl;&#10;        if(i &lt; n) spaces -= 2;&#10;        else spaces += 2;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
    <tr>
      <td>21</td>
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
    <tr>
      <td>22</td>
      <td>Pattern 22 The Number Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 3&#10;Output:&#10;3 3 3 3 3&#10;3 2 2 2 3&#10;3 2 1 2 3&#10;3 2 2 2 3&#10;3 3 3 3 3</code></pre></td>
      <td>1 &le; N &le; 20</td>
      <td><b>Optimal</b></td>
      <td><code>O(N<sup>2</sup>)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td>Grid print naturally restricts space to O(1). Time bounds hardcoded to area N&times;N.</td>
      <td>
        <pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; 2 * n - 1; i++) {&#10;        for(int j = 0; j &lt; 2 * n - 1; j++) {&#10;            int top = i;&#10;            int left = j;&#10;            int right = (2 * n - 2) - j;&#10;            int down = (2 * n - 2) - i;&#10;            cout &lt;&lt; (n - min({top, left, right, down})) &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre>
      </td>
    </tr>
  </tbody>
</table>

<br>

## Basic Maths

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
      <td rowspan="3">1</td>
      <td rowspan="3">Math 01 Count Digits</td>
      <td rowspan="3"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 12345&#10;Output: 5&#10;&#10;Example 2:&#10;Input: N = 8394&#10;Output: 4</code></pre></td>
      <td rowspan="3">1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Sign Edge Case:</b> Fails on N=0. Requires explicit check.</td>
      <td><details><summary>View Code</summary><br><i>Note: Divide by 10 continuously until N becomes 0.</i><br><br><b>Edge Case Code:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">if(n &lt;= 0) return 1;</code></pre><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigitsBrute(int n) {&#10;    // Edge Case: Handle N=0 specifically&#10;    if (n &lt;= 0) return 1;&#10;    int cnt = 0;&#10;    while(n &gt; 0) {&#10;        cnt++;&#10;        n = n / 10;&#10;    }&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Better</b></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><code>O(log10(N))</code><br><i>Trade-off</i></td>
      <td><b>Memory Trade-off:</b> String allocation required. Avoid for strictly O(1) space constraints.</td>
      <td><details><summary>View Code</summary><br><i>Note: Convert number to string and return length.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigitsBetter(int n) {&#10;    // Trade-off: Allocates string memory proportional to digit count&#10;    string s = to_string(n);&#10;    return s.length();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Library Requirement:</b> Must use math library. Fails if standard libraries are restricted.</td>
      <td><details><summary>View Code</summary><br><i>Note: Use base-10 logarithm to find digit count mathematically.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigitsOptimal(int n) {&#10;    // Edge Case check for zero&#10;    if (n &lt;= 0) return 1;&#10;    int cnt = (int)(log10(n) + 1);&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Math 02 Reverse A Number</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 1234&#10;Output: 4321&#10;&#10;Example 2:&#10;Input: N = 10400&#10;Output: 401</code></pre></td>
      <td rowspan="2">-2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Brute Force</b></td>
      <td><code>O(log10(N))</code><br><i>Trade-off</i></td>
      <td><code>O(log10(N))</code><br><i>Trade-off</i></td>
      <td><b>Negative Signs:</b> Reversing a string with '-' results in invalid parsing.</td>
      <td><details><summary>View Code</summary><br><i>Note: Convert to string, reverse the string, and parse back to integer.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverseNumberBrute(int n) {&#10;    // Edge Case: Explicitly store and remove sign before string conversion&#10;    bool isNeg = n &lt; 0;&#10;    string s = to_string(abs(n));&#10;    reverse(s.begin(), s.end());&#10;    int res = stoi(s);&#10;    return isNeg ? -res : res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Overflow Risk:</b> Number fits in 32-bit int, but its reverse might not. Forces explicit checks.</td>
      <td><details><summary>View Code</summary><br><i>Note: Extract digits using modulo 10 and build the reversed number mathematically.</i><br><br><b>Edge Case Code:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">if (revNum &gt; INT_MAX / 10 || revNum &lt; INT_MIN / 10) return 0;</code></pre><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverseNumberOptimal(int n) {&#10;    int revNum = 0;&#10;    while(n != 0) {&#10;        int ld = n % 10;&#10;        // Edge Case: Strict 32-bit overflow check before multiplication&#10;        if (revNum &gt; INT_MAX / 10 || revNum &lt; INT_MIN / 10) return 0;&#10;        revNum = (revNum * 10) + ld;&#10;        n = n / 10;&#10;    }&#10;    return revNum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Math 03 Check Palindrome</td>
      <td rowspan="1"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 121&#10;Output: true&#10;&#10;Example 2:&#10;Input: N = 123&#10;Output: false</code></pre></td>
      <td rowspan="1">-2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Optimal</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Variable Requirement:</b> Number is destroyed during loop, requires `dup` variable for final check.</td>
      <td><details><summary>View Code</summary><br><i>Note: Reverse the number mathematically and compare it to the original.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindromeOptimal(int n) {&#10;    // Edge Case: Negative numbers are strictly not palindromes&#10;    if (n &lt; 0) return false;&#10;    &#10;    int dup = n;&#10;    long long revNum = 0;&#10;    while(n &gt; 0) {&#10;        int ld = n % 10;&#10;        revNum = (revNum * 10) + ld;&#10;        n = n / 10;&#10;    }&#10;    return dup == revNum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Math 04 Gcd Or Hcf</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N1 = 9, N2 = 12&#10;Output: 3&#10;&#10;Example 2:&#10;Input: N1 = 20, N2 = 15&#10;Output: 5</code></pre></td>
      <td rowspan="2">1 &le; N1, N2 &le; 10<sup>9</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(min(N1, N2))</code><br><i>Trade-off</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>TLE Risk:</b> ~10<sup>9</sup> ops heavily exceeds 1 sec limit.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from min(N1, N2) down to 1. The first number dividing both is the GCD.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int gcdBrute(int n1, int n2) {&#10;    for(int i = min(n1, n2); i &gt;= 1; i--) {&#10;        if(n1 % i == 0 &amp;&amp; n2 % i == 0) {&#10;            return i;&#10;        }&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(log(&Phi;)(min(N1, N2)))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Modulo Safety:</b> Euclidean Algorithm easily passes 10<sup>9</sup> via log-scale modulo operations.</td>
      <td><details><summary>View Code</summary><br><i>Note: Euclidean algorithm: gcd(a, b) = gcd(b, a % b) until one becomes 0.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int gcdOptimal(int a, int b) {&#10;    while(a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        // Uses modulo rather than subtraction for logarithmic time complexity&#10;        if(a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    if(a == 0) return b;&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Math 05 Armstrong Numbers</td>
      <td rowspan="1"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 153&#10;Output: true&#10;&#10;Example 2:&#10;Input: N = 170&#10;Output: false</code></pre></td>
      <td rowspan="1">1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Optimal</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Two-Pass Logic:</b> Requires digit count upfront before processing sum of powers.</td>
      <td><details><summary>View Code</summary><br><i>Note: Calculate digit count first, then mathematically extract digits and compute power sums.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isArmstrong(int n) {&#10;    int dup = n;&#10;    int sum = 0;&#10;    int digits = (int)(log10(n) + 1);&#10;    while(n &gt; 0) {&#10;        int ld = n % 10;&#10;        // Uses floating math, convert to int safely&#10;        sum += round(pow(ld, digits));&#10;        n = n / 10;&#10;    }&#10;    return sum == dup;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">6</td>
      <td rowspan="2">Math 06 Print All Divisors</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 36&#10;Output: 1 2 3 4 6 9 12 18 36</code></pre></td>
      <td rowspan="2">1 &le; N &le; 10<sup>6</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(N)</code><br><i>Trade-off</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>TLE Risk:</b> N=10^6 takes ~10<sup>6</sup> ops. Highly inefficient compared to optimal.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from 1 to N and check for divisibility.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDivisorsBrute(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            std::cout &lt;&lt; i &lt;&lt; &quot; &quot;;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(&radic;N * log(&radic;N))</code><br><i>Constraint</i></td>
      <td><code>O(&radic;N)</code><br><i>Trade-off</i></td>
      <td><b>Perfect Squares:</b> Checking `(n / i) != i` explicitly prevents duplicate divisor entries.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate up to sqrt(N) to find pairs of divisors, then sort.</i><br><br><b>Edge Case Code:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">if((n / i) != i) divisors.push_back(n / i);</code></pre><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDivisorsOptimal(int n) {&#10;    std::vector&lt;int&gt; divisors;&#10;    for(int i = 1; i * i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            divisors.push_back(i);&#10;            // Edge Case: Avoid duplicate addition for perfect square roots&#10;            if((n / i) != i) {&#10;                divisors.push_back(n / i);&#10;            }&#10;        }&#10;    }&#10;    std::sort(divisors.begin(), divisors.end());&#10;    for(auto it : divisors) {&#10;        std::cout &lt;&lt; it &lt;&lt; &quot; &quot;;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Math 07 Check For Prime</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 11&#10;Output: true&#10;&#10;Example 2:&#10;Input: N = 15&#10;Output: false</code></pre></td>
      <td rowspan="2">1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(N)</code><br><i>Trade-off</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>TLE Guarantee:</b> N=10^9 takes ~10<sup>9</sup> ops. Guaranteed TLE on any modern platform.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from 2 to N-1 and check divisibility.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPrimeBrute(int n) {&#10;    if (n &lt;= 1) return false;&#10;    for(int i = 2; i &lt; n; i++) {&#10;        if(n % i == 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(&radic;N)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Loop Optimization:</b> `i * i <= n` is far superior to computing `sqrt(n)` repeatedly.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from 2 up to sqrt(N) since divisors come in pairs.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPrimeOptimal(int n) {&#10;    if(n &lt;= 1) return false;&#10;    // Edge Case Optimization: Avoid floating point sqrt overhead by squaring i&#10;    for(int i = 2; i * i &lt;= n; i++) {&#10;        if(n % i == 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>

<br>

