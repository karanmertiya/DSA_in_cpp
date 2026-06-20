// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a hash map or frequency array to count occurrences of each character. Then, iterate through the map/array and print characters with a count greater than 1.

void printDups(string str) {
    unordered_map<char, int> count;
    for(char c : str) count[c]++;
    for(auto it : count) {
        if(it.second > 1) cout << it.first << ", count = " << it.second << "\n";
    }
}

