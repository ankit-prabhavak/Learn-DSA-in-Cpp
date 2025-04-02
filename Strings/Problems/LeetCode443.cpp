#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int compress(vector<char>& chars) {
            int n = chars.size();

            int idx = 0;

            for(int i = 0; i < n; i++){
                char ch = chars[i];
                int count = 0;

                while(i < n && chars[i] == ch){
                    count++;
                    i++;
                }

                if(count == 1){
                    chars[idx++] = ch;
                }
                else{
                    chars[idx++] = ch;
                    string countStr = to_string(count);
                    for(char c : countStr){
                        chars[idx++] = c;
                    }
                }
                i--;
            }
            chars.resize(idx);
            return idx;
            
        }
    };


int main(){
    Solution solution;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int newLength = solution.compress(chars);
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for(int i = 0; i < newLength; i++){
        cout << chars[i] << " ";
    }
    cout << endl;
    // Output: Compressed length: 6
    // Compressed characters: a 2 b 2 c 3
    


    return 0;
}