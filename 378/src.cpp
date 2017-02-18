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

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        queue<pair<int,int>> q;
        q.push(make_pair(matrix[0][0],1));
        int level_flag = 1;
        


    }
};

int main(){

  vector<vector<int> > nums;
  nums = {{1,2},{3,4}};
  int k = 2;
  Solution solution;
  int result = solution.kthSmallest(nums, k);

  cout << result << endl;


    
  return 0;
}