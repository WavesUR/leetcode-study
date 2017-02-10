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
#include <utility>
using namespace std;

// class Solution {
// public:
//     void dp(string p, int start, vector<int>& memo){
//         if(start >= p.length() - 1){
//           return;
//         }
//         if(memo[start] != -1){
//           return;
//         }else{
//           dp(p,start+1,memo);
//         }
//         if(p[start]-p[start+1] == -1 || p[start]-p[start+1] == 'z'-'a'){
//           memo[start] = memo[start+1] + 1;
//         }else{
//           memo[start] = 1;
//         }
//         return;

//     }
//     int findSubstringInWraproundString(string p) {
//         if(p.length() == 0){
//           return 0;
//         }
//         vector<int> memo(p.length(),-1);
//         memo[p.length()-1] = 1;
//         dp(p,0,memo);
//         int sum = 0;
//         unordered_map<char,int> my_map;
//         for(int i = 0; i < p.length(); i++){
//           if(my_map.find(p[i]) == my_map.end()){
//             my_map[p[i]] = memo[i];
//             sum = sum + memo[i];
//           }else if(my_map[p[i]] < memo[i]){
//               sum = sum + memo[i] - my_map[p[i]];
//               my_map[p[i]] = memo[i]; 
//           }       
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.length() == 0){
          return 0;
        }
        vector<int> memo(26,0); // store the number of string which is end with one letter
        memo[p[0]-'a'] = 1;
        int i = 1;
        int max_num = 1;
        while(i < p.length()){
          if(p[i - 1] - p[i] == -1 || p[i-1] - p[i] == 25){
            max_num++;
          }else{
            max_num = 1;
          }
          memo[p[i]-'a'] = max(max_num,memo[p[i] - 'a']);
          i++;
        }
        int sum = 0;
        for(int i = 0; i < memo.size(); i++){
          sum = sum + memo[i];
        }
        return sum;
    }
};

int main(){

  string s = "cdefghefghijklmnopqrstuvwxmnijklmnopqrstuvbcdefghijklmnopqrstuvwabcddefghijklfghijklmabcdefghijklmnopqrstuvwxymnopqrstuvwxyz";
  Solution solution;
  int result = solution.findSubstringInWraproundString(s);

  cout << result << endl;


    
  return 0;
}