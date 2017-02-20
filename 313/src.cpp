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
#include <queue>          // std::priority_queue
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long> > pq;
        pq.push(1);
        long res = 1;
        while(n > 1){
          res = pq.top();
          pq.pop();
          n--;
          while(pq.size() != 0 && res == pq.top()){
            pq.pop();
          }
          for(int i = 0; i < primes.size(); i++){
            // if(res*primes[i] < 0){
            //   break;
            // }
            pq.push(res*primes[i]);
          }
        }
        return (int)pq.top();
    }
};

// class Solution {
// public:
// int nthSuperUglyNumber(int n, vector<int>& primes) {
//         vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
//         ugly[0]=1;
//         for(int i=1; i<n; i++){
//             for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
//             for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
//         }
//         return ugly[n-1];
// }
// };


int main(){

  vector<int> nums;
  nums = {2, 7, 13, 19};
  int k = 12;
   Solution solution;
   int result = solution.nthSuperUglyNumber(k,nums);
 // for(int i = 0; i < result.size();i++){
 //    cout << result[i] << endl;
 // }
   cout << result << endl;


    
  return 0;
}