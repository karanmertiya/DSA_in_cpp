// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Optimal: Sort items in descending order of value/weight ratio. Greedily pick items with the highest ratio first. If an item cannot fit completely, take the fraction that fits.

struct Item { int value; int weight; };
bool static comp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comp);
    double currWeight = 0, finalValue = 0.0;
    for(int i = 0; i < n; i++) {
        if(currWeight + arr[i].weight <= W) {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            double remain = W - currWeight;
            finalValue += (arr[i].value / (double)arr[i].weight) * remain;
            break;
        }
    }
    return finalValue;
}

