#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag1[9][9] = {false},flag2[9][9] = {false},flag3[9][9] = {false};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' + 1;
                    int k = i / 3 * 3 + j / 3;
                    if(flag1[i][num] || flag2[j][num] || flag3[k][num]){
                        return false;
                    }
                    flag1[i][num] = flag2[j][num] = flag3[k][num] = true;
                }

              
            }
        }
        return true;  
    }
};

int main(){

vector<vector<char>>  board;
Solution solution;
solution.isValidSudoku(board);
 
}