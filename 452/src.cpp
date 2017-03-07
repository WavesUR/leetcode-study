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
    int findMinArrowShots(vector<pair<int, int> >& points) {
        if(points.empty()){
            return 0;
        }
        sort(points.begin(),points.end(),[](pair<int,int>& a, pair<int,int>& b){
            if(a.second < b.second || (a.second == b.second && a.first < b.first)){
                return true;
            }else{
                return false;
            }
        });
        for(auto p :points){
            cout << p.first << " " << p.second << endl;
        }
        int arrow = points[0].second;
        int num = 1;
        for(int i = 1; i < points.size(); i++){
            if(arrow <= points[i].second && arrow >= points[i].first){
                continue;
            }
            arrow = points[i].second;
            num++;
        }
        return num;
    }
};

int main(){

    vector<pair<int, int> > intervals = {make_pair(10,16),make_pair(2,8),make_pair(1,6),make_pair(7,12)};
    Solution solution;
    int res = solution.findMinArrowShots(intervals);

    cout << res << endl;

 
}