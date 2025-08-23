#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {

    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans(price.size(), 0);

    stack<int> s;

    for(int i = 0; i < price.size(); i++) {

        while( s.size() > 0 && price[s.top()] <= price[i] ) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = i+1;
        }else {
            ans[i] = i-s.top();
        }

        s.push(i);
    }

    for(auto ele:ans) {
        cout << ele << " ";
    }

    return 0;
}