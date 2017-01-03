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
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int* arr = new int[len+1](); // important
        for(int i = 0; i < len; i++){
          if(citations[i] >= len){
            arr[len]++;
          }else{
            arr[citations[i]]++;
          }
        }
        int count = 0;
        for(int i = len; i>= 0; i--){
          count += arr[i];
          cout << count << endl;
          if(count >= i){
            return i;
          }
        }

        return 0;
    }
};

int main(){

  vector<int> citations;
  citations = {0, 0};
  Solution solution;
  int result = solution.hIndex(citations);
  // for(int i = 0; i < citations.size();i++){
  //   cout  << citations[i] << " ";
  // }
  cout << result << endl;


    
  return 0;
}