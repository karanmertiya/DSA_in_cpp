// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void printPattern(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = 0; j < 2 * (n - i) - 1; j++) cout << "*";
        for(int j = 0; j < i; j++) cout << " ";
        cout << endl;
    }
}

int main() {
    int n = 5;
    printPattern(n);
    return 0;
}
