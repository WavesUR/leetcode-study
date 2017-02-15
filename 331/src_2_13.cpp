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
        stack<char> my_stack;
        int i = 0;
        bool isNum = true;
        while(i < preorder.size()){
          if(preorder[i] == ','){
              isNum = true;
          }
          else if(preorder[i] == '#'){
            int temp = preorder[i];
            while(my_stack.size() > 1 && temp == '#' && my_stack.top() == '#'){
              my_stack.pop();
              if(my_stack.empty() || my_stack.top() == '#'){
                return false;
              }
              my_stack.pop();
            }
              my_stack.push(temp);
              isNum = true;
          }
          else if(isNum){
            my_stack.push(preorder[i] );
            isNum = false;
          }
          i++;
            
        }
        if(my_stack.size() == 1 && my_stack.top() == '#'){
          return true;
        }else{
          return false;
        }
    }
};

int main(){

  string s = "#,#,#";
  Solution solution;
  bool result = solution.isValidSerialization(s);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}