#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class MinStack {
public:
    stack<long long int> s;
    long long int minVal;
    MinStack() {

        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minVal = val;
        }else {
            if(val >= minVal) {
                s.push(val);
            }else {
                s.push(2LL * val - minVal);
                minVal = val;
            }
        }


    }
    
    void pop() {
        if(s.empty()) return;
        long long int top = s.top();
        s.pop();
        if(top < minVal) {
            minVal = 2LL * minVal - top;
        }
        
    }
    
    int top() {
        if(s.empty()) return -1;
        long long int top = s.top();
        if(top >= minVal) {
            return top;
        }else {
            return minVal;
        }
        
    }
    
    int getMin() {

            return minVal;
    }
};


/*
 Time complexity: O(1)
 Space complexity: O(n)

class MinStack {
public:
    stack<pair<int, int>> s;
    MinStack() {

        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        }else {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
         return s.top().second;
    }
};

*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */