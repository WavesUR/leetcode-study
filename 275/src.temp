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
        int left = 0;
        int right = len - 1;
        int mid = 0;
        while(left <= right){
          mid = left + (right - left)/2;
          if(citations[mid] >= len - mid){
            right = mid - 1;
          }else{
            left = mid + 1;
          }
        }

        return len - left;
    }
};

int main(){

  vector<int> citations;
  citations = {0,1,3,4,6};
  Solution solution;
  int result = solution.hIndex(citations);
  // for(int i = 0; i < citations.size();i++){
  //   cout  << citations[i] << " ";
  // }
  cout << result << endl;


    
  return 0;
}