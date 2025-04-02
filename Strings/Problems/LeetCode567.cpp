#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool isFreqSame(int F1[], int F2[]){
            for(int i=0; i <26; i++){
                if(F1[i] != F2[i]){
                    return false;
                }
            }
            return true;
        }
        
        bool checkInclusion(string s1, string s2) {
            int freq[26] = {0};
    
            for(int i = 0; i < s1.length(); i++ ){
                freq[s1[i]- 'a']++;
            }
    
            int windowSze = s1.length();
            
            for(int i = 0; i < s2.length(); i++){
                int windIdx = 0, idx = i;
                int wFreq[26] = {0};
    
                while(windIdx < windowSze && idx < s2.length()){
                    wFreq[s2[idx]-'a']++;
                    windIdx++; idx++;
    
                }
    
                if(isFreqSame(freq, wFreq)){
                    return true;
                }
            }
    
            return false;
            
        }
    };


int main(){
    Solution solution;
    string s1 = "abc";
    string s2 = "eidbaooo";

    bool result = solution.checkInclusion(s1, s2); // Check if s1's permutation is in s2
    cout << "Is s1's permutation in s2? " << (result ? "Yes" : "No") << endl; // Output: Yes
    // This will print "Is s1's permutation in s2? Yes"

    return 0;
}