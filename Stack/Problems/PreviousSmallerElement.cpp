#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    vector<int> arr = {3, 1, 0, 8, 6};

    vector<int> ans(arr.size(), -1);


    stack<int> s;

    for(int i = 0; i <arr.size(); i++) {

        while( s.size() > 0 && s.top() >= arr[i] ) {
            s.pop();
        }

        if(!s.empty()) {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(auto ele:ans) {
        cout << ele << " ";
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)