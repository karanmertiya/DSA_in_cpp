// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
string chooseandswap(string a) {
    set<char> s;
    for(char c : a) s.insert(c);
    for(int i = 0; i < a.length(); i++) {
        s.erase(a[i]);
        if(s.empty()) break;
        char ch = *s.begin();
        if(ch < a[i]) {
            char ch1 = a[i], ch2 = ch;
            for(int j = 0; j < a.length(); j++) {
                if(a[j] == ch1) a[j] = ch2;
                else if(a[j] == ch2) a[j] = ch1;
            }
            break;
        }
    }
    return a;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Store the first occurrence index of all characters. Iterate the string, for each character check if there is a lexicographically smaller character that appears later in the string. If so, swap them and break.

string chooseandswap(string a) {
    set<char> s;
    for(char c : a) s.insert(c);
    for(int i = 0; i < a.length(); i++) {
        s.erase(a[i]);
        if(s.empty()) break;
        char ch = *s.begin();
        if(ch < a[i]) {
            char ch1 = a[i], ch2 = ch;
            for(int j = 0; j < a.length(); j++) {
                if(a[j] == ch1) a[j] = ch2;
                else if(a[j] == ch2) a[j] = ch1;
            }
            break;
        }
    }
    return a;
}

