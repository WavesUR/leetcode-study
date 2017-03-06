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
    // 00: die -> die
    // 01: live -> die
    // 10: die ->live
    // 11: live->live 
    void gameOfLife(vector<vector<int> >& board) {
        vector<vector<int> > r = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < board.size(); i++){
          for(int j = 0; j < board[0].size(); j++){
            int live = 0;
            for(int k = 0; k < 8; k++){
              int x = i + r[k][0];
              int y = j + r[k][1];
              if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()){
                continue;
              }
              if(board[x][y] == 1 || board[x][y] == 3){
                live++;
              }
            }
            if(board[i][j] == 1 && (live < 2 || live > 3) ){
              board[i][j] = 1;
            }else if(board[i][j] == 1 && (live == 2 || live == 3)){
              board[i][j] = 3;
            }else if(board[i][j] == 0 && (live == 3) ){
              board[i][j] = 2;
            }
          }
        }
        for(int i = 0; i < board.size(); i++){
          for(int j = 0; j < board[0].size();j++){
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