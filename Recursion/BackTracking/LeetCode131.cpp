#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
    public:

        bool isPalin(string s){
            string s2 = s;
            reverse(s2.begin(), s2.end());
            return s2 == s;
        }
        
        void getAllPart(string s, vector<string> &part, vector<vector<string>> &ans){
            if(s.size() == 0){
                ans.push_back(part);
                return;
            }

            for(int i = 0; i < s.size(); i++){
                string temp = s.substr(0, i + 1);

                if(isPalin(temp)){
                    part.push_back(temp);
                    getAllPart(s.substr(i + 1), part, ans);
                    part.pop_back();
                }
            }

        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> part;

            getAllPart(s, part, ans);

            return ans;
        }
    };

int main(){
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
            }
            cout << endl;
            }
            return 0;
}