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
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> map(26,0);
        for(int i = 0; i < magazine.size();i++){
          map[magazine[i]-'a']++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
          map[ransomNote[i]-'a']--;
          if(map[ransomNote[i]-'a'] < 0){
            return false;
          }
        }
        return true;
    }
};


int main(){
  vector<int>  nums;
  nums = {1,2,1,3,2,5};
  Solution solution;

  bool result = solution.canConstruct("as","sd");
  cout << result << endl;


    
  return 0;
}