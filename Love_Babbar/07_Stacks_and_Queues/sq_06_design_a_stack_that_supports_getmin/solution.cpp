// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: To achieve O(1) space, when pushing `x < minEle`, push `2 * x - minEle` and update `minEle = x`. When popping `y`, if `y < minEle`, then `minEle = 2 * minEle - y`.

int minEle;
void push(stack<int>& s, int a){
    if(s.empty()) { s.push(a); minEle = a; }
    else if(a < minEle) { s.push(2 * a - minEle); minEle = a; }
    else { s.push(a); }
}
bool isFull(stack<int>& s, int n){
    return s.size() == n;
}
bool isEmpty(stack<int>& s){
    return s.empty();
}
int pop(stack<int>& s){
    if(s.empty()) return -1;
    int top = s.top();
    s.pop();
    if(top < minEle) {
        int prevMin = minEle;
        minEle = 2 * minEle - top;
        return prevMin;
    }
    return top;
}
int getMin(stack<int>& s){
    return minEle;
}

