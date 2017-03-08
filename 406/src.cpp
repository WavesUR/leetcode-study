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
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        sort(people.begin(),people.end(),[](pair<int,int>& a, pair<int,int>& b){
            if(a.first > b.first || (a.first == b.first && a.second < b.second)){
                return true;
            }else{
                return false;
            }
        });
        vector<pair<int,int> > res;
        for(auto p : people){
            res.insert(res.begin()+p.second,p);
        }

        return res;
    }
};

int main(){

vector<pair<int, int> > intervals = {make_pair(7,0),make_pair(4,4),make_pair(7,1),make_pair(5,0),make_pair(6,1),make_pair(5,2)};


Solution solution;
vector<pair<int, int> > res = solution.reconstructQueue(intervals);

for(auto r : res){
  cout << r.first << " " << r.second << endl;
}
cout << endl;

    
    return 0;
}