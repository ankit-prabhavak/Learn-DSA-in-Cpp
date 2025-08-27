#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

long minimumLoss(const vector<long>& price) {
    int n = price.size();
    map<long, int> priceToIndex;
    for (int i = 0; i < n; ++i) {
        priceToIndex[price[i]] = i;
    }

    vector<long> sortedPrice = price;
    sort(sortedPrice.begin(), sortedPrice.end(), greater<long>());

    long minLoss = LONG_MAX;
    for (int i = 0; i < n - 1; ++i) {
        long higher = sortedPrice[i];
        long lower = sortedPrice[i + 1];
        // Only consider if lower was bought after higher (i.e., index of lower > index of higher)
        if (priceToIndex[lower] > priceToIndex[higher]) {
            minLoss = min(minLoss, higher - lower);
        }
    }
    return minLoss;
}

// Example usage
int main() {
    vector<long> price = {20, 7, 8, 2, 5};
    cout << minimumLoss(price) << endl; // Output: 2
    return 0;

}