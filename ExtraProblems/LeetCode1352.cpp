#include <iostream>
#include <vector>

using namespace std;

// Leetcode 1352: Product of Last K Numbers
class ProductOfNumbers {
private:
    vector<int> ans;  // Stores prefix product

public:
    ProductOfNumbers() {
        ans.push_back(1);  
    }
    
    void add(int num) {
        if (num == 0) {
            ans.clear();
            ans.push_back(1); 
        } else {
            ans.push_back(ans.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= ans.size()) return 0;
        return ans.back() / ans[ans.size() - k - 1];
    }
};


// Time Complexity:
// - add: O(1)
// - getProduct: O(1) (constant time division)
// Space Complexity: O(n) where n is the number of elements added (due to the vector storing products)
// Note: The vector `ans` stores the prefix products, allowing efficient retrieval of the product