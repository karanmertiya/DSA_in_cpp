// Time Complexity: O(log10 x)
// Space Complexity: O(1)
// Explanation: Negative numbers are false. Reverse half the number. If original equals reversed, it is a palindrome.

bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) return false;
    int reversedHalf = 0;
    while(x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }
    return x == reversedHalf || x == reversedHalf / 10;
}

