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
#include <queue>
using namespace std;
//Heap
//Time: O(klog3k) ???
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         priority_queue<long, vector<long>, greater<long> > minHeap;
//         minHeap.push(1);
//         while(n > 1){
//           auto temp = minHeap.top();
//           minHeap.pop();
//           n--;
//           while(minHeap.size() != 0 && temp == minHeap.top()){
//             minHeap.pop();
//           }
//             minHeap.push(temp*2);
//             minHeap.push(temp*3);
//             minHeap.push(temp*5);
//         }
//         return (int)minHeap.top();
//     }
// };
//Dynamic Programming
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        int i = 0;
        int j = 0;
        int k = 0;
        int temp = 1;
        while(n > 1){
          temp = min(v[i]*2, min(v[j]*3,v[k]*5));
          v.push_back(temp);
          if(temp == v[i]*2){
            i++;
          }
          if(temp ==v[j]*3){
            j++;
          }
          if(temp == v[k]*5){
            k++;
          } 
          n--;         
        }
        return temp;

    }
};

int main(){

  vector<vector<int> > nums;
  nums = {{1,5,9},{10,11,13},{12,13,15}};
  int k = 10;
  Solution solution;
  int result = solution.nthUglyNumber(k);

  cout << result << endl;


    
  return 0;
}