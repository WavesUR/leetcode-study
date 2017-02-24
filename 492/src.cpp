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


class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w;
        for(int i = 1; i * i <= area;i++){
            if(area%i == 0){
                w = i;
            }
        }
        return {area/w,w};
    }
};
int main(){

    int num = 4;
    Solution solution;
    vector<int> res = solution.constructRectangle(num);
    for(auto r : res){
        cout << r << endl;
    }

 
}