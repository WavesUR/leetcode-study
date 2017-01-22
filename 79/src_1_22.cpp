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
    bool backtrack(vector<vector<char> >& board, string word, int cur, int row, int col,int& row_max, int& col_max, int& word_len){
        if(cur >= word_len || row < 0 || row >= row_max || col < 0 || col >= col_max || word[cur] != board[row][col]){
          return false;
        }

        if(cur == word_len - 1){
          return true;
        }

        char temp = board[row][col];
        board[row][col] = '\0';
        if(backtrack(board,word,cur+1,row-1,col,row_max,col_max,word_len) || backtrack(board,word,cur+1,row+1,col,row_max,col_max,word_len) || backtrack(board,word,cur+1,row,col-1,row_max,col_max,word_len) || backtrack(board,word,cur+1,row,col+1,row_max,col_max,word_len)){
          return true;
        }
        board[row][col] = temp;
        return false;

    }
    bool exist(vector<vector<char> >& board, string word) {
        int cur = 0;
        int row_max = board.size();
        int col_max = board[0].size();
        int word_len = word.length();
        for(int row = 0; row < row_max; row++){
          for(int col = 0; col < col_max; col++){
            if(backtrack(board,word,cur,row,col,row_max,col_max,word_len)){
              return true;
            }
          }
        }
        
        return false;
      }
};

int main(){

  vector<vector<char> > board;
  board = {{'A','B','C','E'},
  {'S','F','C','S'},
  {'A','D','E','E'}};
  string word = "ABCCED";
  Solution solution;
  bool result = solution.exist(board, word);
  // for(int i = 0; i< result.size();i++){
  //   for(int j = 0; j < result[i].size();j++){
  //     cout << result[i][j] << " ";
  //   }  
  //   cout << endl;
  // }
  cout << result << endl;


    
  return 0;
}