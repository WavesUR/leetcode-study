#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if(numRows < 1){
            return res;
        }
        
        for(int r = 0; r < numRows; r++){
            vector<int> temp;
            for(int c = 0; c <= r ; c++){                
                if(c == 0 || c == r){
                    temp.push_back(1);
                }else{
                    temp.push_back(res[r-1][c-1]+res[r-1][c]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){

    vector<vector<int> > PT;
	Solution solution;	
    PT = solution.generate(5);      
    for(int i = 0; i < PT.size();i++){
        for(int j = 0; j < PT[i].size();j++){
            cout << PT[i][j] << " ";
        }
        cout << endl;
    }



//    cout << result << endl;


    
	return 0;
}