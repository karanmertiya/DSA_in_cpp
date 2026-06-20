// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void printPattern(int n) {
    for(int i = 0; i < n; i++) {
        for(char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    printPattern(5);
    return 0;
}

