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



struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len == 0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](Interval& a, Interval& b){ 
            if(a.end < b.end || (a.end == b.end && a.start > b.start)){
                return true;
            }else{
                return false;
            }
        });
        for(auto i : intervals){
            cout << i.start << " " << i.end << endl;
        }
        int num = 1;
        int end = intervals[0].end;
        for(int i = 1; i < len; i++){
            if(intervals[i].start < end){
                continue;
            }
            end = intervals[i].end;
            num++;
        }

        return len-num;
    }
};

int main(){

    vector<Interval> intervals = {Interval(1,2),Interval(2,3),Interval(3,4),Interval(1,3),Interval(1,5)};
    Solution solution;
    int res = solution.eraseOverlapIntervals(intervals);

    cout << res << endl;

 
}