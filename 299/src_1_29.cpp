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
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> map_s(10, 0);
//        vector<int> map_g(10,0);
        int cout_a = 0;
        int cout_b = 0;
        for(int i = 0; i < guess.length(); i++){
          if(guess[i] == secret[i]){
            cout_a++;
          }else{
            int si = secret[i] - '0';
            int gi = guess[i] - '0';

            if(map_s[si] < 0){
              cout_b++;
            }
             map_s[si]++;           

            if(map_s[gi] > 0){
              cout_b++;
            }
            map_s[gi]--;
          }
        }
        return to_string(cout_a) + 'A' + to_string(cout_b) + 'B';
    }
};

int main(){

  string secret = "1807";
  string guess  = "7810";
  Solution solution;
  string result = solution.getHint(secret, guess);
  cout << result << endl;


    
  return 0;
}