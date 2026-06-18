// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void printPattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    printPattern(n);
    return 0;
}
