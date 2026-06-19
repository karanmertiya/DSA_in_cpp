// Time Complexity: O(1) or O(set bits)
// Space Complexity: O(1)
// Explanation: The XOR of A and B will have set bits only at positions where A and B differ. Thus, we just need to count the set bits in `A ^ B`.

int countBitsFlip(int a, int b){
    int n = a ^ b;
    int count = 0;
    while(n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

