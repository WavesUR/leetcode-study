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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int cur = 0;
        int tank = 0;
        int start = 0;
        int total = 0;
        for(int i = 0; i < len; i++){
          total = total + gas[i] - cost[i];
        }
        if(total < 0){
          return -1;
        }
        while(cur < len){
          tank = tank + gas[cur] - cost[cur];
          if(tank >= 0){
            cur++;
          }else{
            while(tank <= 0 && cur < len){
              tank = gas[cur] - cost[cur];
              start = cur;
              cur++;
            }
          }
        }
        return start;
    }
};
int main(){
  vector<int>  gas = {1,2,3,4,5};
  vector<int>  cost = {3,4,5,6};
  Solution solution;
  int result = solution.canCompleteCircuit(gas,cost);
  cout << result << endl;


    
  return 0;
}