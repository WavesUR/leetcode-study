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
    vector<int> helper(vector<string>& input_s, int start, int end){
      vector<int> res;      
      if(start == end){
        res.push_back(stoi(input_s[start]));
        return res;
      }
      vector<int> a , b;

      for(int i = start; i <= end; i++){
        if(input_s[i] == "+" || input_s[i] == "-" || input_s[i] == "*"){
          a = helper(input_s,start,i-1);
          b = helper(input_s,i+1,end);
          for(int j = 0; j < a.size();j++){
            for(int k = 0; k < b.size();k++){
              if(input_s[i] == "+"){
                res.push_back(a[j]+b[k]);
              }else if(input_s[i] == "-"){
                res.push_back(a[j]-b[k]);
              }else{
                res.push_back(a[j]*b[k]);
              }
            }
          }
        }
      }
      return res;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<string> input_s;
        int start = 0;
        int i;
        for(i = 0; i < input.length(); i++){
          if(isdigit(input[i])){
            continue;
          }else{
            input_s.push_back(input.substr(start,i-start));
            start = i + 1;
            input_s.push_back(input.substr(i,1));
          }
        }
        input_s.push_back(input.substr(start,i-start));
        return helper(input_s, 0, input_s.size()-1);
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