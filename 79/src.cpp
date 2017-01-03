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
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(helper(board, word, 0, i, j, m, n)){
              return true;
            }
          }
        }
        return false;
    }
    bool helper(vector<vector<char> >& board, string& word, int cur, int x, int y, int m, int n){
        if(x >= m || x < 0 || y < 0 || y >= n || board[x][y] != word[cur]){
          return false;
        }
        if(cur == word.length()-1){
          return true;
        }
        char t = board[x][y];
        board[x][y] = '\0';
      if(helper(board, word, cur+1, x-1, y, m, n) || helper(board, word, cur+1, x+1, y, m, n) || helper(board, word, cur+1, x, y-1, m, n) || helper(board, word, cur+1, x, y+1, m, n)){
        return true;
      }
      board[x][y] = t;
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