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
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int r = 0; r <= rowIndex; r++){           
            for(int c = r; c  > 0; c--){
                    res[c] = res[c-1] + res[c];
            }
        }
        return res;
    }
};

int main(){

    vector<int> PT;
	Solution solution;	
    PT = solution.getRow(4);      
    for(int i = 0; i < PT.size();i++){
            cout << PT[i]<< " ";
        
    }
cout << endl;

    
	return 0;
}