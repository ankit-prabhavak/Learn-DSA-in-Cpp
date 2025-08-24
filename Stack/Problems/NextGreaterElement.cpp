#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> ans(arr.size(), -1);


    stack<int> s;

    for(int i = arr.size()-1; i >= 0; i--) {

        while( s.size() > 0 && arr[s.top()] <= arr[i] ) {
            s.pop();
        }

        if(!s.empty()) {
            ans[i] = arr[s.top()];
        }

        s.push(i);
    }

    for(auto ele:ans) {
        cout << ele << " ";
    }

    return 0;
}

