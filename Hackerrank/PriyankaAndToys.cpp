#include <bits/stdc++.h>

using namespace std;

int toys(vector<int> w) {
     int container = 1;
     int mini = INT8_MAX;
     for(auto& ele: w) {
        if(ele < mini) mini = ele;
     }
     
     mini += 4;
     
     sort(w.begin(), w.end());
     
     for(auto& toy: w) {
        if(toy > mini) {
            mini = toy + 4;
            container += 1;
        }
     }
     
     return container;
    
}


int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    cout << toys(w) << endl;
    
    return 0;
}