#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        
    }
};

int main(){

vector<Interval> intervals = {Interval(1,4),Interval(2,3),Interval(3,4)}


Solution solution;
vector<int> res = solution.findRightInterval(intervals);

for(int i = 0; i < res.size(); i++){
  cout << res[i] << " ";
}
cout << endl;

    
    return 0;
}