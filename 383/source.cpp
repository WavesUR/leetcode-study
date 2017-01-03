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
        int lenr = ransomNote.length();
        int lenm = magazine.length();
        if(lenm < lenr){
            return false;
        }
        if(lenr == 0){
          return true;
        }
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int i = 0, j = 0;
        while(j < lenm){
            if(ransomNote[i] == magazine[j]){
                if(i==lenr - 1){
                    return true;
                }
                i++;
                j++;
            }else{
                j++;
            }
        }
        return false;
    }
};


int main(){
  vector<int>  nums;
  nums = {1,2,1,3,2,5};
  Solution solution;

  bool result = solution.canConstruct("","");
  cout << result << endl;


    
  return 0;
}