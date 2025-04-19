#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
    public:
        set<vector<int>> s;
       
        void getAllComb(vector<int>& candidates, int idx, int target, vector<vector<int>> &res, vector<int> &comb){
            if(idx == candidates.size() || target < 0){
                return;
            }

            if(target == 0){
                if(s.find(comb) == s.end()){
                    s.insert(comb);
                    res.push_back(comb);
                }
                return;

            }

            comb.push_back(candidates[idx]);
            //single
            getAllComb(candidates, idx+1, target - candidates[idx], res, comb);
            //multiple
            getAllComb(candidates, idx, target - candidates[idx], res, comb);
            comb.pop_back();
            // empty
            getAllComb(candidates, idx+1, target, res, comb);
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> comb;
            getAllComb(candidates, 0, target, res, comb);
            return res;
            
        }
    };


int main(){
    Solution solution;
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
            cout << endl;
    }
    
    return 0;
}