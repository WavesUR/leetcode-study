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

// // Time: O(nlogn)
// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         sort(citations.rbegin(),citations.rend());
//         int index = 0;
//         for(int i = 0; i < citations.size(); i++){
//           if(citations[i] >= i + 1){
//             index = i + 1;
//           }else{
//             break;
//           }
//         }
//         return index;
//       }
// };


// Time: O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
          int len = citations.size();
          vector<int> map(len+1,0);
          int index = 0;
          for(int i = 0; i < len; i++){
            if(citations[i] > len){
              map[len]++;
            }else{
              map[citations[i]]++;
            }
          }

          for(int i = len; i >= 0; i--){
            index = index + map[i];
            if(index >= i){
              return i;
            }
          }
          return 0;

      }
};

int main(){

  vector<int> citations;
  citations = {3, 0, 6, 1, 5};
  Solution solution;
  int result = solution.hIndex(citations);
  // for(int i = 0; i < citations.size();i++){
  //   cout  << citations[i] << " ";
  // }
  cout << result << endl;


    
  return 0;
}