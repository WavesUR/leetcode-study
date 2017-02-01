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
        if(len == 0){
          return 0;
        }
        int left = 0, right = len-1, mid;
        while(left < right){
          mid = left + (right - left) / 2;
          if(citations[mid] >= len - mid){
            right = mid;
          }else{
            left = mid + 1;
          }
        }
        return citations[right] >= len - right ? len - right : 0;
    }
};
int main(){

  vector<int> citations;
  citations = {0};
  Solution solution;
  int result = solution.hIndex(citations);
  // for(int i = 0; i < citations.size();i++){
  //   cout  << citations[i] << " ";
  // }
  cout << result << endl;


    
  return 0;
}