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
    pair<int,int> my_pair(string str){
        int temp_m = 0;
        int temp_n = 0;
        for(int j = 0; j < str.length(); j++){
          if(str[j] == '0'){
            temp_m++;
          }else{
            temp_n++;
          }
        }      
      return make_pair(temp_m,temp_n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cur = 0;
        int count = 0;
        int result = 0;
        vector<vector<int> > memo(m+1, vector<int>(n+1,0));
        for(auto s : strs){
          pair<int,int> pr = my_pair(s);
          for(int i = m; i >= pr.first; i--){
            for(int j = n; j >= pr.second; j--){
              memo[i][j] = max(memo[i][j],memo[i - pr.first][j - pr.second] + 1);
            }
          }
          
        }
        return memo[m][n];
    }
};

int main(){

  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5, n = 3;
  Solution solution;
  int result = solution.findMaxForm(strs, m, n);
  cout << result << endl;



    
  return 0;
}