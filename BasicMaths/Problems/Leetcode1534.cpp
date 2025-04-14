#include <iostream>
#include <vector>
#include <cmath> // For abs function

using namespace std;



class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int goodTriplets = 0;
            int length = arr.size();
    
            for (int i = 0; i < length; i++) {
                for (int j = i + 1; j < length; j++) {
                    if (abs(arr[i] - arr[j]) <= a) {
                        for (int k = j + 1; k < length; k++) {
                            if (abs(arr[j] - arr[k]) <= b &&
                                abs(arr[i] - arr[k]) <= c) {
                                goodTriplets++;
                              
                            }
                        }
                    }
                }
            }
    
            return goodTriplets;
        }
    };


int main() {
    Solution solution;
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7;
    int b = 2;
    int c = 3;
    
    int result = solution.countGoodTriplets(arr, a, b, c);
    cout << "Number of good triplets: " << result << endl; // Output: 4
    
    return 0;
}
// Output: 4