#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.length() == 0){
          return false;
        } 
        int cur_s = 0;
        int cur_l = 0;
        int i = 0;
        vector<int> v;
        return helper(num, cur_l, cur_l, i, v);
    }

    bool helper(string & num, int cur_s, int cur_l, int i, vector<int> & v){
            if(num[cur_s] == '0'){
                return false;
            }       
        if(cur_l == num.length() - 1){
            if(i < 2 || v[i - 1] + v[i - 2] != stoi(num.substr(cur_s,cur_l-cur_s+1),nullptr)) {
                return false;
            }
            return true;
        }

            v.push_back(stoi(num.substr(cur_s,cur_l-cur_s+1),nullptr));
            if(i >= 2){
                if(v[i] == v[i-1]+v[i-2]){
                    if(helper(num, cur_l+1, cur_l+1, i+1, v)){
                        return true;
                    }
                }
            }
            if(helper(num, cur_l+1, cur_l+1, i+1, v)){
                return true;
            }   
            v.pop_back();

            if(helper(num, cur_s, cur_l+1, i, v)){
                return true;
            }

            
            return false;
    }
};

int main(){

  string s = "198019823962";
   Solution solution;
   bool result = solution.isAdditiveNumber(s);
 // int i = stoi(s.substr(2),nullptr);
  cout << result << endl;


    
  return 0;
}