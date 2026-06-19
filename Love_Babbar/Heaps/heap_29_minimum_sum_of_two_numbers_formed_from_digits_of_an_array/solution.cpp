// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Sort the array. Build two strings representing the two numbers by picking digits alternately from the sorted array. Add the two large numbers as strings or build the result dynamically.

string solve(int arr[], int n) {
    sort(arr, arr + n);
    string a = "", b = "";
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) a += to_string(arr[i]);
        else b += to_string(arr[i]);
    }
    string res = "";
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        res += to_string(sum % 10);
        carry = sum / 10;
    }
    while(res.length() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

