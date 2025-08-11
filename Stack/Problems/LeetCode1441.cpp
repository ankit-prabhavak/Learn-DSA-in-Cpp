#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> operations;

        int current = 1; // Start from 1

        for (int i = 0; i < target.size(); ++i) {

            while (current < target[i]) {
                operations.push_back("Push");
                operations.push_back("Pop");
                current++;
            }
            operations.push_back("Push");
            current++; 

        }

       
        return operations;
    }
};