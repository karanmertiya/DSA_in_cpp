// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void printPattern(int n) {
    int iniSpace = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= n - i; j++) cout << "*";
        for(int j = 0; j < iniSpace; j++) cout << " ";
        for(int j = 1; j <= n - i; j++) cout << "*";
        iniSpace += 2;
        cout << endl;
    }
    iniSpace = 2 * n - 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) cout << "*";
        for(int j = 0; j < iniSpace; j++) cout << " ";
        for(int j = 1; j <= i; j++) cout << "*";
        iniSpace -= 2;
        cout << endl;
    }
}

int main() {
    printPattern(5);
    return 0;
}
