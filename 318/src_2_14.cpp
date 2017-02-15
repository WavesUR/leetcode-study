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
        vector<int> word_int(words.size(),0);
        for(int i = 0; i < words.size();i++){
          for(int j = 0; j < words[i].length();j++){
            word_int[i] = word_int[i] | (1 << (words[i][j] - 'a'));
          }
        }
        int max_len = 0;
        for(int i = 0; i < words.size();i++){
          for(int j = i + 1; j < words.size();j++ ){
            if(!(word_int[i] & word_int[j])){
              max_len = max(max_len,(int)words[i].length()*(int)words[j].length());
            }
          }
        }
        return max_len;
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