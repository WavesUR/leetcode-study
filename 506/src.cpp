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
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int> > map;
        for(int i = 0; i < nums.size(); i++){
            map.push_back(make_pair(i,nums[i]));
        }
        sort(map.begin(),map.end(),[](pair<int,int>& a, pair<int,int>& b){return a.second > b.second;});
        vector<string> res(map.size(),"");
        for(int i = 0; i < map.size(); i++){
            if(i == 0){
                res[map[i].first] = "Gold Medal";
            }else if(i == 1){
                res[map[i].first] = "Silver Medal";
            }else if(i == 2){
                res[map[i].first] = "Bronze Medal";
            }else{
               res[map[i].first] = to_string(i+1); 
            }
            
        }
        return res;
    }
};
int main(){

    vector<int> num = {2,3,4,5,1};
    Solution solution;
    vector<string> res = solution.findRelativeRanks(num);
    for(auto r : res){
        cout << r << endl;
    }

 
}