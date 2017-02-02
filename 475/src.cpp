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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MAX);
        heaters.push_back(INT_MIN);
        sort(heaters.begin(), heaters.end());
        long long res = 0;
        for (auto p : houses){
            int p1 = lower_bound(heaters.begin(), heaters.end(), p)-heaters.begin();
            int p2 = p1-1;
            long long temp = min( ((long long)heaters[p1]-p), ((long long)p-heaters[p2]));
            res = max(res, temp);
        }
        return res;      
    } 
};

int main(){

  vector<int> houses = {1,5};
  vector<int> heaters = {10};

  Solution solution;
  int result = solution.findRadius(houses,heaters);
  cout << result << endl;


    
  return 0;
}