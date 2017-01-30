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
        int len = board.size();
        vector<vector<int> > map_i(len, vector<int>(len,0));
        vector<vector<int> > map_j(len, vector<int>(len,0));
        vector<vector<int> > map_k(len, vector<int>(len,0));
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int k = (i / 3) * 3 + j / 3;
                    if(map_i[i][num] || map_j[j][num] || map_k[k][num]){
                        return false;
                    }
                    map_i[i][num] = 1;
                    map_j[j][num] = 1;
                    map_k[k][num] = 1;                    
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