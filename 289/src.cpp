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
    void gameOfLife(vector<vector<int>>& board) {
       if(board.empty()){
        return;
       }
       int h = board.size();
       int w = board[0].size(); 
       int around[8][2] = { 
      { -1, -1 }, { -1, 0 }, { -1, 1 },
      { 0, -1 },             { 0, 1 },
      { 1, -1 },  { 1, 0 },  { 1, 1 }
    };
    for(int i = 0; i < h ; i++){
      for(int j = 0; j < w; j++){
        int num = 0;
        for(int k = 0; k < 8; k++){
          int x = i + around[k][0];
          int y = j + around[k][1];
          if(x > -1 && x < h && y > -1 && y < w){
            num += (board[x][y] & 0x1);
          }
          }
          if(board[i][j] == 0){
            if(num == 3){
              board[i][j] |= 0x2;
            }
          }else{
            if(num == 2 || num == 3){
              board[i][j] |= 0x2;
            }
          }
        
      }
    }
    for(int i = 0; i <h; i++){
      for(int j = 0; j< w;j++){
        board[i][j] = board[i][j] >> 1;
      }
    }
    }

};

int main(){

  vector<vector<int> > matrix;
  matrix = {{1,1},{1,0}};
  Solution solution;
  solution.gameOfLife(matrix);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  //cout << result << endl;


    
  return 0;
}