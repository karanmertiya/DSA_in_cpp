// Time Complexity: O(sqrt(N))
// Space Complexity: O(1)
// Explanation: If `num <= 1`, return false. Iterate up to `sqrt(num)`. If `i` divides `num`, add `i` and `num/i` to the sum. After the loop, compare sum with `num`.

bool checkPerfectNumber(int num) {
    if(num <= 1) return false;
    int sum = 1;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            sum += i;
            if(i * i != num) sum += num / i;
        }
    }
    return sum == num;
}

