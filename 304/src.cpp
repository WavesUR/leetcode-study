#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <map>
using namespace std;


// class NumMatrix {
// public:
// 	vector<vector<int > > map;
//     NumMatrix(vector<vector<int> > matrix) {
//         if (matrix.size() == 0) return;
//         map = vector<vector<int> >(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
//         for(int i = map.size() - 2; i >= 0; i--){
//         	for(int j = map.size() - 2; j >=0; j--){
//         		map[i][j] = matrix[i][j] + map[i+1][j] + map[i][j+1] - map[i+1][j+1];
//         	}
//         }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         return map[row1][col1] - map[row2+1][col1] - map[row1][col2+1] + map[row2+1][col2+1];
//     }
// };

class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

int main(){

    vector<vector<int> > matrix = {
    	  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}
    };

    NumMatrix numMatrix(matrix);
    int res = numMatrix.sumRegion(1,1,2,2);
    cout << res << endl;

 
}