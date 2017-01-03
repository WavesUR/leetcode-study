#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.length();
        return helper(input, 0, len-1);
    }
    vector<int> helper(string & input,  int begin, int end){
      vector<int> result;
      if(begin > end){
        return result;
      }
//      cout << begin << end << endl;
      for(int i = begin; i<= end; i++){
//          cout << i << endl;        
        if(!isdigit(input[i])){
          vector<int> ops1 = helper(input, begin, i-1);
          vector<int> ops2 = helper(input, i+1, end);

          for(int j = 0; j < ops1.size(); j++){
            for(int k = 0; k < ops2.size(); k++){
              switch(input[i]){
                case '-': result.push_back(ops1[j] - ops2[k]);break;
                case '+': result.push_back(ops1[j] + ops2[k]);break;
                case '*': result.push_back(ops1[j] * ops2[k]);break;
                default: break;
              }
            }
          }          
        }

      }
      if(result.empty()){
          result.push_back(stoi(input.substr(begin,end-begin+1)));
        }
        return result;
    }
};
int main(){

  string s = "2*3-4*5";
  Solution solution;
  vector<int> result = solution.diffWaysToCompute(s);
  for(int i = 0; i< result.size();i++){
    cout << result[i] << endl;
  }
  //out << result << endl;


    
  return 0;
}