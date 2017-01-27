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
    int hour(vector<int>& v){
        int res = 0;
        for(int i = 0; i < 4; i++){
            res = res + v[i] * pow(2,3-i);
        }
        return res;
    }
    int min(vector<int>& v){
        int res = 0;
        for(int i = 4; i < 10; i++){
            res = res + v[i] * pow(2,9-i);
        }
        return res;
    }    
    void backtrack(int num, int cur, string& s, vector<int>& v, vector<string>& res){
        if(num == 0) {
            
            int h = hour(v);
            int m = min(v);          
            if(h < 12 && m < 60){
               if(m < 10){
                   s = to_string(h) + ':' + '0' + to_string(m); 
                }else{
                   s = to_string(h) + ':' + to_string(m); 
                }              
                res.push_back(s);           
            }
            return;
        }

        for(int i = cur; i < 10; i++){
            v[i] = 1;
            backtrack(num - 1, i+1, s, v ,res);
            v[i] = 0;            
        }

    }
    //     void backtrack(int num, int cur, string& s, vector<int>& v, vector<string>& res){
    //     if(cur == 10) {
    //         int m = min(v);
    //         string t = s;
    //         if(m < 60 && num == 0){
    //             if(m < 10){
    //                s = s + '0'; 
    //             } 
    //             s = s + to_string(m);               
    //             res.push_back(s);
    //         }
    //         s = t;
    //         return;
    //     }

    //     if(cur == 4){
    //         int h = hour(v);
    //         if(h < 12){
    //            s = to_string(h) + ':'; 
    //         }else {
    //             return;}
    //     }


    //     if(num > 0){
    //         v.push_back(1);
    //         backtrack(num - 1, cur+1, s, v ,res);
    //         v.pop_back();
    //     }
        
    //     v.push_back(0);
    //     backtrack(num, cur+1, s, v ,res);
    //     v.pop_back();


    // }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        string s;
        vector<int> v(10,0);
        int cur = 0;
        backtrack(num, cur, s, v ,res);
        return res;
    }
};


int main(){

int nums = 0;
Solution solution;
vector<string> result = solution.readBinaryWatch(nums);
for(int i = 0; i < result.size(); i++){
    cout << result[i] << endl;
}
    
return 0;
  
}