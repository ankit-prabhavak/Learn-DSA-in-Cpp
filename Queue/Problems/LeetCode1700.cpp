#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> stu(students.begin(), students.end());
        deque<int> sand(sandwiches.begin(), sandwiches.end());
        int count = 0;

        while (!stu.empty() && count < stu.size()) {
            if (stu.front() == sand.front()) {
                stu.pop_front();
                sand.pop_front();
                count = 0;
            } else {
                stu.push_back(stu.front());
                stu.pop_front();
                count++;
            }
        }
        return stu.size();
    }
};