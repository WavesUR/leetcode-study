#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
      int len = preorder.size();

      if(len == 0){
        return false;
      }
      bool isNum = false;      
      preorder.push_back(',');
      stack<char> mystack;
      for(int i = 0; i <= len; i++){
          if(preorder[i] == '#'){
             while(!mystack.empty() && mystack.top() == '#'){
            mystack.pop();
            if(mystack.empty() || mystack.top() == '#'){
              return false;
            }
            mystack.pop();
          }
            mystack.push('#');  
          }else if(preorder[i] == ','){
                if(isNum) mystack.push('n');
                isNum = false;            
          }else{
            isNum = true;
          }           
         
          
      }

      return mystack.size() == 1 && mystack.top() == '#'? true : false;
    }
};

int main(){

  string s = "9,#,92,#,#";
  Solution solution;
  bool result = solution.isValidSerialization(s);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}