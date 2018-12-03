#include <cctype>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <cstdio>     
#include <cstdlib>
using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = matrix.size() - 1; i >= 0; i--){
            for(int j = matrix[0].size() - 1; j >=0; j--){
                if(i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> ops = {{1,2},{2,2}};
    bool ret = solution.isToeplitzMatrix(ops);
    cout << ret << endl;
    return 0;
}