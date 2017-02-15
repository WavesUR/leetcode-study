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
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int result = 0;
        for(int i = 0; i < words.size(); i++){
          for(int j = 0; j < words[i].length();j++){
            mask[i] = mask[i] | (1 << words[i][j] - 'a');
          }
          for(int k = 0; k < i; k++){
            if(!(mask[i] & mask[k])){
              result = max(result,int(words[i].length()*words[k].length()));
            }
            
          }
        }
        return result;
    }
};


int main(){
  vector<string>  nums;
  nums = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  Solution solution;

  int result = solution.maxProduct(nums);
  cout << result << endl;


    
  return 0;
}