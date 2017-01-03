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

    int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.empty()){
          return 0;
        }
        int layer = triangle.size();
        vector<int> temp(layer);
        temp = triangle[layer-1];
        for(int i = layer - 2; i >= 0; i--){
          for(int j = 0; j <= i; j++){
            temp[j] = min(temp[j], temp[j+1])+triangle[i][j];
          }
        }
        return temp[0];
    }
};

int main(){

  vector<vector<int> > nums;
  nums = {{2},{3,4},{6,5,7},{4,1,8,3}};
  Solution solution;
  int result = solution.minimumTotal(nums);

  cout << result << endl;


    
  return 0;
}