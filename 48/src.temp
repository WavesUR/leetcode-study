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
    void rotate(vector<vector<int> >& matrix) {
        int len = matrix.size();
        int layer = len / 2;
        cout << len << endl;

        for(int i = 0; i < layer; i++){
          int first = i;
          int last = first + len - 2*i - 2;
          cout << first << last << endl;
          for (int j = first; j <= last; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[len-j-1][i];
            matrix[len-j-1][i] = matrix[len-i-1][len-j-1];
            matrix[len-i-1][len-j-1] = matrix[j][len-i-1];
            matrix[j][len-i-1] = temp;
          }
        }
    }
};

int main(){

  vector<vector<int> > grid(4,vector<int>(4,-1));
  Solution solution;
  solution.rotate(grid);    
  return 0;
}