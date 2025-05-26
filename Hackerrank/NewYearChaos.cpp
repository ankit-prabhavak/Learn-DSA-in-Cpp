/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

#include <iostream>
#include <vector>
using namespace std;

void minimumBribes(vector<int> q) {
    int count = 0;
    int n = q.size();

    // Check for "Too chaotic"
    for (int i = 0; i < n; i++) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
    }

    // Count the number of bribes
    for (int i = 0; i < n; i++) {
        // Only need to check from one position ahead of original position up to current
        for (int j = max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) {
                count++;
            }
        }
    }

    cout << count << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    minimumBribes(q);

    return 0;
}